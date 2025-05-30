#pragma once

#include <WinSock2.h>

class JFTPSession {
public:
    FtpSession(SOCKET socket);
    void operator()();
private:
    SOCKET clientSocket;
    void Send(const char* message);
    void HandleCommands();
};

