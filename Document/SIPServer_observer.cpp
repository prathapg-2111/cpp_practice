#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <unordered_map>
#include <arpa/inet.h>
#include <thread>
#include <vector>
#include <functional>

#define SIP_PORT 5060
#define BUFFER_SIZE 1024

// Base class for handling different types of SIP requests
class SIPRequestHandler
{
public:
    virtual void handleRequest(const char *buffer, sockaddr_in &client_addr, int server_fd) = 0;
    virtual ~SIPRequestHandler() {}
};

// INVITE Request Handler
class SIPInviteHandler : public SIPRequestHandler
{
public:
    void handleRequest(const char *buffer, sockaddr_in &client_addr, int server_fd) override
    {
        // Process INVITE message here
        std::string response = "SIP/2.0 180 Ringing\r\n";
        sendto(server_fd, response.c_str(), response.size(), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        std::cout << "Sent SIP INVITE response.\n";
    }
};

// REGISTER Request Handler
class SIPRegisterHandler : public SIPRequestHandler
{
public:
    void handleRequest(const char *buffer, sockaddr_in &client_addr, int server_fd) override
    {
        // Process REGISTER message here
        std::string response = "SIP/2.0 200 OK\r\n";
        sendto(server_fd, response.c_str(), response.size(), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));
        std::cout << "Sent SIP REGISTER response.\n";
    }
};

// Context to handle different strategies (SIP message handlers)
class SIPServerContext
{
public:
    void setRequestHandler(std::unique_ptr<SIPRequestHandler> handler)
    {
        request_handler = std::move(handler);
    }

    void handleRequest(const char *buffer, sockaddr_in &client_addr, int server_fd)
    {
        if (request_handler)
        {
            request_handler->handleRequest(buffer, client_addr, server_fd);
        }
    }

private:
    std::unique_ptr<SIPRequestHandler> request_handler;
};

// Main SIP Server class
class SIPServer
{
public:
    SIPServer() : server_fd(-1) {}

    ~SIPServer()
    {
        if (server_fd != -1)
        {
            close(server_fd);
        }
    }

    bool initialize()
    {
        server_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (server_fd < 0)
        {
            perror("Socket creation failed");
            return false;
        }

        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(SIP_PORT);

        if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            perror("Bind failed");
            return false;
        }

        std::cout << "SIP server started on port " << SIP_PORT << std::endl;
        return true;
    }

    void run()
    {
        while (true)
        {
            std::thread client_handler(&SIPServer::handleClientRequests, this);
            client_handler.detach(); // Detach thread for concurrent processing
        }
    }

private:
    int server_fd;
    SIPServerContext context;

    void handleClientRequests()
    {
        char buffer[BUFFER_SIZE];
        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        ssize_t received_len = recvfrom(server_fd, buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&client_addr, &client_len);
        if (received_len < 0)
        {
            perror("Receive failed");
            return;
        }

        buffer[received_len] = '\0'; // Null-terminate the message

        std::cout << "Received SIP message:\n"
                  << buffer << std::endl;

        // Determine the type of SIP message (INVITE, REGISTER, etc.)
        if (strstr(buffer, "INVITE"))
        {
            context.setRequestHandler(std::make_unique<SIPInviteHandler>());
        }
        else if (strstr(buffer, "REGISTER"))
        {
            context.setRequestHandler(std::make_unique<SIPRegisterHandler>());
        }

        context.handleRequest(buffer, client_addr, server_fd);
    }
};

int main()
{
    SIPServer server;

    if (!server.initialize())
    {
        std::cerr << "Failed to initialize the SIP server\n";
        return 1;
    }

    server.run();
    return 0;
}
