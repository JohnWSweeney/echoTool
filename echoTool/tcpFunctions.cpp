#include "tcpFunctions.h"
#include "clientServer.h"

void startServer(int portNum)
{
	Server newServer;
	newServer.run(portNum);
}