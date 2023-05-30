#include "start.h"
#include "udpFunctions.h"
#include "atomicBool.h"

void getInput(std::vector<std::string> &tokens)
{
	// Copy each word in user input to vector (tokenize).
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

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
		catch (...) {
			std::cout << "Invalid port number. Try again.\n";
		}
	}
	else if (tokens[1] == "stop")
	{
		echoStatus = false;
	}
	else
	{
		std::cout << "Invalid command. Try again.\n";
	}
}

void startMenu(bool &running, std::vector<std::string> &tokens)
{
	// start new thread running echo function.
	if (tokens[0] == "echo")
	{
		startEchoThread(tokens);
	}
	// stop all active threads.
	else if (tokens[0] == "stop")
	{
		if (tokens[1] == "all")
		{
			echoStatus = false;
			std::cout << "All threads stopped.\n";
		}
		else
		{
			std::cout << "Invalid command. Try again.\n";
		}
	}
	// Terminate active threads, program.
	else if (tokens[0] == "exit")
	{
		echoStatus = false;
		running = false;
		Sleep(1000);
	}
	// Reject all other inputs.
	else
	{
		std::cout << "Invalid input. Try again.\n";
	}
	tokens.clear();
}