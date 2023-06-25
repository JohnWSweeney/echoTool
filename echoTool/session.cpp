#include "session.h"
#include "tcp.h"
#include "atomicBool.h"

void Session::run(SOCKET socket)
{
	this->echo(socket);
}

void Session::echo(SOCKET socket)
{
	tcp echo;
	msg newMsg;
	int result = echo.rx(socket, newMsg.buffer, newMsg.bufferLen);
	if (result > 0)
	{
		std::cout << "Message received: " << newMsg.buffer << '\n';
		std::cout << "Message size: " << result << " bytes\n";
		int sendResult = echo.tx(socket, newMsg.buffer, result);
		if (sendResult == SOCKET_ERROR)
		{
			std::cout << "Echo failed with error: " << WSAGetLastError() << '\n';
			closesocket(socket);
			WSACleanup();
			return;
		}
		else
		{
			std::cout << "Message echoed.\n";
		}
	}
	closesocket(socket);
}

void startSession(SOCKET socket)
{
	Session newSession(socket);
	newSession.run(socket);
}
