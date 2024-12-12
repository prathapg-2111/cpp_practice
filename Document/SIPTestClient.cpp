#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h> // Added for inet_pton

#define SERVER_PORT 5060
#define SERVER_ADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024

class SIPClient
{
public:
    SIPClient() : client_fd(-1), authenticated(false) {}

    ~SIPClient()
    {
        if (client_fd != -1)
        {
            close(client_fd);
        }
    }

    bool initialize()
    {
        // Create a UDP socket
        client_fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (client_fd < 0)
        {
            perror("Socket creation failed");
            return false;
        }

        // Configure the server address
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        if (inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr) <= 0)
        {
            perror("Invalid server address");
            return false;
        }

        std::cout << "SIP client initialized\n";
        return true;
    }

    void sendInvite()
    {
        std::string invite = createInviteMessage();

        // Send the INVITE message
        ssize_t sent_len = sendto(client_fd, invite.c_str(), invite.size(), 0,
                                  (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (sent_len < 0)
        {
            perror("Send failed");
            return;
        }

        std::cout << "Sent SIP INVITE message:\n"
                  << invite << std::endl;

        // Receive the response
        char buffer[BUFFER_SIZE];
        sockaddr_in response_addr;
        socklen_t response_len = sizeof(response_addr);

        ssize_t received_len = recvfrom(client_fd, buffer, BUFFER_SIZE - 1, 0,
                                        (struct sockaddr *)&response_addr, &response_len);
        if (received_len < 0)
        {
            perror("Receive failed");
            return;
        }

        buffer[received_len] = '\0';
        std::cout << "Received SIP response:\n"
                  << buffer << std::endl;

        // Handle responses
        if (isAuthenticationRequired(buffer))
        {
            std::cout << "Authentication required. Resending INVITE with credentials." << std::endl;
            authenticated = true;
            sendInvite();
        }
        else if (isRingingResponse(buffer))
        {
            std::cout << "Received 180 Ringing response. Waiting for further response..." << std::endl;
            // Handle ringing state, maybe wait or handle timeout here
            waitForResponse();
        }
        else if (isOkResponse(buffer))
        {
            std::cout << "Received 200 OK response. Call initiated successfully!" << std::endl;
            // Proceed with further actions if needed (e.g., start call processing)
        }
        else
        {
            std::cout << "Received unexpected response: " << buffer << std::endl;
        }
    }

private:
    int client_fd;
    sockaddr_in server_addr;
    bool authenticated;

    std::string createInviteMessage()
    {
        std::string invite = "INVITE sip:user@domain.com SIP/2.0\r\n";
        invite += "Via: SIP/2.0/UDP 127.0.0.1:5060\r\n";
        invite += "From: sip:caller@domain.com\r\n";
        invite += "To: sip:user@domain.com\r\n";
        invite += "Call-ID: 123456789\r\n";
        if (authenticated)
        {
            invite += "Authorization: Digest username=\"user\", realm=\"domain.com\", nonce=\"123456\", uri=\"sip:user@domain.com\", response=\"abcdef1234567890\"\r\n";
        }
        invite += "Content-Length: 0\r\n\r\n";
        return invite;
    }

    bool isAuthenticationRequired(const std::string &response)
    {
        return response.find("401 Unauthorized") != std::string::npos && response.find("WWW-Authenticate") != std::string::npos;
    }

    bool isRingingResponse(const std::string &response)
    {
        return response.find("180 Ringing") != std::string::npos;
    }

    bool isOkResponse(const std::string &response)
    {
        return response.find("200 OK") != std::string::npos;
    }

    void waitForResponse()
    {
        char buffer[BUFFER_SIZE];
        sockaddr_in response_addr;
        socklen_t response_len = sizeof(response_addr);

        // Wait for further response from the server
        ssize_t received_len = recvfrom(client_fd, buffer, BUFFER_SIZE - 1, 0,
                                        (struct sockaddr *)&response_addr, &response_len);
        if (received_len < 0)
        {
            perror("Receive failed");
            return;
        }

        buffer[received_len] = '\0';
        std::cout << "Waiting for final response...\n";
        std::cout << "Received final response: " << buffer << std::endl;
    }
};

int main()
{
    SIPClient client;

    if (!client.initialize())
    {
        std::cerr << "Failed to initialize the SIP client\n";
        return 1;
    }

    client.sendInvite();
    return 0;
}
