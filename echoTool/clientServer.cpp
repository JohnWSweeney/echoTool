#include "clientServer.h"
#include "tcp.h"
#include "atomicBool.h"

void Session::run(SOCKET socket)
{
	tcp session;
	msg newMsg;
	int result = session.rx(socket, newMsg.buffer, newMsg.bufferLen);
	if (result > 0)
	{
		std::cout << "Message received: " << newMsg.buffer << '\n';
		std::cout << "Message size: " << result << " bytes\n";
		int sendResult = session.tx(socket, newMsg.buffer, result);
		if (sendResult == SOCKET_ERROR)
		{
			std::cout << "echo failed with error: " << WSAGetLastError() << '\n';
			closesocket(socket);
			WSACleanup();
			return;
		}
		else
		{
			std::cout << "Message echoed.\n\n";
		}
	}
	closesocket(socket);
}

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

	//bool running = true;
	do {
		result = server.socketReadStatus(sockStruct.listenSocket);
		if (result > 0)
		{
			int res = server.acceptConnection(sockStruct);
			if (res == 0)
			{
				auto session = std::make_shared<Session>(std::move(sockStruct.acceptSocket));
				session->run(sockStruct.acceptSocket);
			}
			
		}
	//} while (running);
	} while (serverStatus);
	server.closeSocket(sockStruct.listenSocket);
	std::cout << "Server terminated on port " << portNum << ".\n";
}