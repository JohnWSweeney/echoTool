#pragma once
#include "tcp.h"

class Session : public std::enable_shared_from_this<Session>
{
public:
	Session(SOCKET socket)
	{
		std::cout << "new session.\n";
	}
	void run(SOCKET socket);
};

class Server
{
public:
	Server()
	{
		std::cout << "server started.\n\n";
	}
	void run(int portNum);
};