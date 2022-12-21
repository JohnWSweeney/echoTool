#include "udp.h"
#include "select.h"

extern std::atomic<bool> echoStatus;

void echo(int localPortNum)
{
	udpSocket udpEcho;
	udpEcho.openSocket(localPortNum);

	int result = 0;
	std::cout << "Listening...\n" << std::endl;
	datagram rxDatagram;
	while (echoStatus)
	{
		result = udpEcho.rx(rxDatagram);
		if (result > 0)
		{
			std::cout << "Echo:" << std::endl;
			std::cout << "Source address: " << inet_ntoa(rxDatagram.sin_addr) << std::endl;
			std::cout << "Source port: " << rxDatagram.sin_port << std::endl;
			std::cout << "Payload size: " << rxDatagram.payloadLen << std::endl;
			std::cout << "Payload: " << rxDatagram.payload << "\n" << std::endl;
			udpEcho.tx(inet_ntoa(rxDatagram.sin_addr), rxDatagram.sin_port, rxDatagram.payload, rxDatagram.payloadLen);
		}
	}

	udpEcho.closeSocket();
}