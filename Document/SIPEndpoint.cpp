#include <iostream>
#include <string>
#include <map>

// SIPMessage Class
class SIPMessage
{
public:
    std::string type; // Request type (e.g., INVITE, ACK, BYE)
    std::map<std::string, std::string> headers;
    std::string body;

    SIPMessage(const std::string &type, const std::string &body = "")
        : type(type), body(body) {}

    void addHeader(const std::string &key, const std::string &value)
    {
        headers[key] = value;
    }

    void print() const
    {
        std::cout << "SIP Message: " << type << "\nHeaders:\n";
        for (const auto &[key, value] : headers)
        {
            std::cout << key << ": " << value << "\n";
        }
        std::cout << "Body: " << body << "\n";
    }
};

// SIPTransport Class
class SIPTransport
{
public:
    void send(const SIPMessage &message, const std::string &destination)
    {
        std::cout << "Sending SIP message to " << destination << "...\n";
        message.print();
    }

    SIPMessage receive()
    {
        // Simulated incoming message
        return SIPMessage("INVITE", "SDP data here...");
    }
};

// SIPSession Class
class SIPSession
{
private:
    std::string sessionID;
    std::string state;

public:
    SIPSession(const std::string &id) : sessionID(id), state("INIT") {}

    void accept()
    {
        state = "CONNECTED";
        std::cout << "Session " << sessionID << " accepted. State: " << state << "\n";
    }

    void terminate()
    {
        state = "TERMINATED";
        std::cout << "Session " << sessionID << " terminated. State: " << state << "\n";
    }

    std::string getState() const { return state; }
};

// SIPEndpoint Class
class SIPEndpoint
{
private:
    SIPTransport transport;
    std::map<std::string, SIPSession> sessions;

public:
    void sendInvite(const std::string &destination)
    {
        SIPMessage invite("INVITE");
        invite.addHeader("To", destination);
        invite.addHeader("From", "sip:user@domain.com");
        invite.addHeader("Call-ID", "12345");

        transport.send(invite, destination);
        sessions["12345"] = SIPSession("12345");
    }

    void receiveMessage()
    {
        SIPMessage message = transport.receive();
        if (message.type == "INVITE")
        {
            std::cout << "Incoming call. Accepting...\n";
            SIPSession session("67890");
            session.accept();
            sessions["67890"] = session;
        }
    }

    void terminateCall(const std::string &sessionID)
    {
        if (sessions.find(sessionID) != sessions.end())
        {
            sessions[sessionID].terminate();
        }
        else
        {
            std::cout << "No session with ID " << sessionID << " found.\n";
        }
    }
};

int main()
{
    SIPEndpoint endpoint;

    // Simulate sending an INVITE
    endpoint.sendInvite("sip:destination@domain.com");

    // Simulate receiving a message
    endpoint.receiveMessage();

    // Terminate a call
    endpoint.terminateCall("12345");

    return 0;
}
