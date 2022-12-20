#include "udp.h"
#include "select.h"

std::atomic<bool> echoStatus;

void start()
{
	bool running = true;
	std::string input, tempStr;
	std::vector<std::string> tokens;

	while (running)
	{
		getline(std::cin, input, '\n');
		std::stringstream strStream(input);

		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}

		if (tokens[0] == "echo")
		{
			if (tokens[1] == "start")
			{
				try {
					int portNum = std::stoi(tokens[2]);
					echoStatus = true;
					std::thread echoThread(echo, portNum, 0, 1);
					echoThread.detach();
					//std::cout << "echo started." << std::endl;
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
				std::cout << "Invalid status. Try again dummy." << std::endl;
			}
		}
		else if (tokens[0] == "exit")
		{
			running = false;
			std::cout << "Exiting..." << std::endl;
			Sleep(4000);
		}
		else
		{
			std::cout << "Invalid process. Try again dummy." << std::endl;
		}
		tokens.clear();
	}
}