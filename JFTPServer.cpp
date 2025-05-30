#include "JFTPServer.h"
#include "JFTPSession.h"
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

JFTP::JFTP() {}

JFTP::~JFTP() {
    Stop();
}

bool JFTP::Start(int port) {
    if (running) return false;
    running = true;
    serverThread = std::thread(&FtpServer::RunServer, this, port);
    return true;
}

void JFTP::Stop() {
    running = false;
    if (serverThread.joinable())
        serverThread.join();
}

void JFTP::RunServer(int port) {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr = {};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    while (running) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket != INVALID_SOCKET) {
            std::thread(FtpSession(clientSocket)).detach();
        }
    }

    closesocket(serverSocket);
    WSACleanup();
}

