#include "start.h"

int main()
{
	std::cout << "echoTool v1.1.1\n\n";
	bool running = true;
	std::vector<std::string> tokens;
	while (running)
	{
		getInput(tokens);
		startMenu(running, tokens);
	}
}