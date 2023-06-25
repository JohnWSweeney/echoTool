#include "threads.h"
#include "server.h"
#include "session.h"
#include "udpFunctions.h"
#include "atomicBool.h"

void startEchoThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "start")
	{
		try {
			int portNum = std::stoi(tokens[2]);
			echoStatus = true;
			std::thread echoThread(echo, portNum);
			echoThread.detach();
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid port number.\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "Port number is out of range.\n";
		}
	}
	else if (tokens[1] == "stop")
	{
		echoStatus = false;
	}
	else
	{
		std::cout << "Invalid start/stop command.\n";
	}
}

void startSessionThread(SOCKET socket)
{
	try {
		std::thread sessionThread(startSession, socket);
		sessionThread.detach();
	}
	catch (...)
	{
		std::cout << "Session start failed.\n";
	}
}

void startServerThread(std::vector<std::string> &tokens)
{
	if (tokens[1] == "start")
	{
		try {
			int portNum = std::stoi(tokens[2]);
			serverStatus = true;
			std::thread echoThread(startServer, portNum);
			echoThread.detach();
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid port number.\n";
		}
		catch (std::out_of_range)
		{
			std::cout << "Port number is out of range.\n";
		}
	}
	else if (tokens[1] == "stop")
	{
		serverStatus = false;
	}
	else
	{
		std::cout << "Invalid start/stop command.\n";
	}
}