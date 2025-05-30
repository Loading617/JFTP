#pragma once

#include <Core/Core.h>
#include <thread>

class FtpServer {
public:
    FtpServer();
    ~FtpServer();
    bool Start(int port);
    void Stop();

private:
    std::thread serverThread;
    bool running = false;
    void RunServer(int port);
};
