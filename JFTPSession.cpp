#include "JFTPSession.h"
#include <cstring>
#include <string>

JFTPSession::JFTPSession(SOCKET socket) : clientSocket(socket) {}

void JFTPSession::operator()() {
    Send("220 Welcome to JFTP Server\r\n");
    HandleCommands();
    closesocket(clientSocket);
}

void JFTPSession::Send(const char* message) {
    send(clientSocket, message, strlen(message), 0);
}

void JFTPSession::HandleCommands() {
    char buffer[1024];
    while (true) {
        int received = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (received <= 0) break;
        buffer[received] = 0;
        std::string cmd(buffer);
        if (cmd.starts_with("USER")) {
            Send("331 Username OK, need password\r\n");
        } else if (cmd.starts_with("PASS")) {
            Send("230 Login successful\r\n");
        } else if (cmd.starts_with("QUIT")) {
            Send("221 Goodbye\r\n");
            break;
        } else {
            Send("502 Command not implemented\r\n");
        }
    }
}

