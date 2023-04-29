#include "echoTool.h"
#include "udp.h"
#include <string>
#include <sstream>
#include <Windows.h>
#include <thread>
#include <atomic>

std::atomic<bool> echoStatus;

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
			std::cout << "Invalid port number. Try again dummy." << std::endl;
		}
	}
	else if (tokens[1] == "stop")
	{
		echoStatus = false;
	}
	else
	{
		std::cout << "Invalid command. Try again." << std::endl;
	}
}

void selectThread(bool &running, std::vector<std::string> &tokens)
{
	if (tokens[0] == "echo")
	{
		startEchoThread(tokens);
	}
	// Terminate active thread, program.
	else if (tokens[0] == "exit")
	{
		echoStatus = false;
		running = false;
		Sleep(1000);
	}
	// Reject all other inputs.
	else
	{
		std::cout << "Invalid input. Try again." << std::endl;
	}
	tokens.clear();
}

void start()
{
	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		selectThread(running, tokens);
	}
}