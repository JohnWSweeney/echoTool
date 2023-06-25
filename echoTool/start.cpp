#include "start.h"
#include "threads.h"
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

void startMenu(bool &running, std::vector<std::string> &tokens)
{
	// start new thread running echo function.
	if (tokens[0] == "echo")
	{
		startEchoThread(tokens);
	}
	// stop all active threads.
	else if (tokens[0] == "server")
	{
		startServerThread(tokens);
	}
	else if (tokens[0] == "stop")
	{
		if (tokens[1] == "all")
		{
			echoStatus = false;
			serverStatus = false;
		}
		else
		{
			std::cout << "Invalid command.\n";
		}
	}
	// Terminate active threads, program.
	else if (tokens[0] == "exit")
	{
		echoStatus = false;
		serverStatus = false;
		running = false;
		Sleep(1000);
	}
	// Reject all other inputs.
	else
	{
		std::cout << "Invalid function command.\n";
	}
	tokens.clear();
}