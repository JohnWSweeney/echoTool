#pragma once
#include <iostream>
#include <WinSock2.h>

class Session : public std::enable_shared_from_this<Session>
{
public:
	Session(SOCKET socket)
	{
		std::cout << "New session.\n";
	}
	~Session()
	{
		std::cout << "Session ended.\n\n";
	}
	void run(SOCKET socket);
	void echo(SOCKET socket);
};

void startSession(SOCKET socket);