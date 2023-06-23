#include "udpFunctions.h"
#include "atomicBool.h"
#include "udp.h"

void echo(int localPortNum)
{
	udp udpEcho;
	int result = udpEcho.openSocket(localPortNum);
	if (result != 0)
	{
		std::cout << "openSocket failed.\n";
		echoStatus = false;
	}
	else
	{
		std::cout << "Echoing on port " << localPortNum << "...\n\n";
	}

	datagram rxDatagram;
	int packetsEchoed = 0;
	while (echoStatus)
	{
		result = udpEcho.rx(rxDatagram);
		if (result > 0)
		{
			std::cout << "Echoed on port: " << localPortNum << '\n';
			std::cout << "Source address: " << inet_ntoa(rxDatagram.sin_addr) << '\n';
			std::cout << "Source port: " << rxDatagram.sin_port << '\n';
			std::cout << "Payload size: " << rxDatagram.payloadLen << '\n';
			std::cout << "Payload: " << rxDatagram.payload << '\n';
			udpEcho.tx(inet_ntoa(rxDatagram.sin_addr), rxDatagram.sin_port, rxDatagram.payload, rxDatagram.payloadLen);
			++packetsEchoed;
			std::cout << "Packets echoed since runtime: " << packetsEchoed << "\n\n";
		}
	}
	udpEcho.closeSocket();
	std::cout << "Echo terminated on port " << localPortNum << ".\n";
}