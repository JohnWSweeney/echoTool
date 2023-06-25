#include "server.h"
#include "threads.h"
#include "tcp.h"
#include "atomicBool.h"

void Server::run(int portNum)
{
	tcp server;
	sockStruct sockStruct;
	int result = server.openSocket(portNum, sockStruct);
	if (result != 0)
	{
		return;
	}

	result = server.bindListen(sockStruct);
	if (result != 0)
	{
		return;
	}
	else
	{
		std::cout << "Server started.\n\n";
	}

	do {
		result = server.socketReadStatus(sockStruct.listenSocket);
		if (result > 0)
		{
			int acceptResult = server.acceptConnection(sockStruct);
			if (acceptResult == 0)
			{
				startSessionThread(std::move(sockStruct.acceptSocket));
			}
		}
	} while (serverStatus);
	server.closeSocket(sockStruct.listenSocket);
	std::cout << "Server terminated on port " << portNum << ".\n";
}

void startServer(int portNum)
{
	Server newServer;
	newServer.run(portNum);
}