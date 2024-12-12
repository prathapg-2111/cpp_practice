    #include <iostream>
    #include <cstring>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #include <string>
    #include <unordered_map>
    #include <arpa/inet.h>
    #include <thread>
    #include <vector>

    #define SIP_PORT 5060
    #define BUFFER_SIZE 1024

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
            // Create a UDP socket
            server_fd = socket(AF_INET, SOCK_DGRAM, 0);
            if (server_fd < 0)
            {
                perror("Socket creation failed");
                return false;
            }

            // Bind the socket to the SIP port
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
                // Accept and process incoming requests from clients in separate threads
                std::thread client_handler(&SIPServer::handleClientRequests, this);
                client_handler.detach(); // Detach the thread to handle many clients concurrently
            }
        }

    private:
        int server_fd;
        std::unordered_map<std::string, bool> authenticated_clients; // Tracks authenticated clients

        void handleClientRequests()
        {
            char buffer[BUFFER_SIZE];
            sockaddr_in client_addr;
            socklen_t client_len = sizeof(client_addr);

            // Receive SIP message from client
            ssize_t received_len = recvfrom(server_fd, buffer, BUFFER_SIZE - 1, 0,
                                            (struct sockaddr *)&client_addr, &client_len);
            if (received_len < 0)
            {
                perror("Receive failed");
                return;
            }

            buffer[received_len] = '\0'; // Null-terminate the message

            std::cout << "Received SIP message:\n"
                    << buffer << std::endl;

            std::string client_ip = inet_ntoa(client_addr.sin_addr);
            uint16_t client_port = ntohs(client_addr.sin_port);
            std::string client_key = client_ip + ":" + std::to_string(client_port);

            std::string response;
            if (authenticated_clients.find(client_key) == authenticated_clients.end())
            {
                if (strstr(buffer, "Authorization"))
                {
                    // Validate Authorization header (basic check for nonce match)
                    if (strstr(buffer, "nonce=\"123456\""))
                    {
                        authenticated_clients[client_key] = true;
                        response = "SIP/2.0 200 OK\r\n";
                        response += "Via: SIP/2.0/UDP 127.0.0.1:" + std::to_string(SIP_PORT) + "\r\n";
                        response += "Content-Length: 0\r\n\r\n";
                    }
                    else
                    {
                        response = "SIP/2.0 403 Forbidden\r\n";
                        response += "Via: SIP/2.0/UDP 127.0.0.1:" + std::to_string(SIP_PORT) + "\r\n";
                        response += "Content-Length: 0\r\n\r\n";
                    }
                }
                else
                {
                    response = "SIP/2.0 401 Unauthorized\r\n";
                    response += "Via: SIP/2.0/UDP 127.0.0.1:" + std::to_string(SIP_PORT) + "\r\n";
                    response += "WWW-Authenticate: Digest realm=\"domain.com\", nonce=\"123456\"\r\n";
                    response += "Content-Length: 0\r\n\r\n";
                }
            }
            else
            {
                response = "SIP/2.0 200 OK\r\n";
                response += "Via: SIP/2.0/UDP 127.0.0.1:" + std::to_string(SIP_PORT) + "\r\n";
                response += "Content-Length: 0\r\n\r\n";
            }

            sendto(server_fd, response.c_str(), response.size(), 0,
                (struct sockaddr *)&client_addr, client_len);

            std::cout << "Sent SIP response:\n"
                    << response << std::endl;
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
