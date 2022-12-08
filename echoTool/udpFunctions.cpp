#include "udp.h"

void echo(int localPortNum, long s, long us)
{
	udpSocket udpEcho;
	udpEcho.openSocket(localPortNum);

	int result = 0;
	std::cout << "listening...\n" << std::endl;
	datagram rxDatagram;
	while (result == 0)
	{
		result = udpEcho.rx(rxDatagram, s, us);
		if (result > 0)
		{
			std::cout << "Echo:" << std::endl;
			std::cout << "Source address: " << inet_ntoa(rxDatagram.sin_addr) << std::endl;
			std::cout << "Source port: " << rxDatagram.sin_port << std::endl;
			std::cout << "Payload size: " << rxDatagram.payloadLen << std::endl;
			std::cout << "Payload: " << rxDatagram.payload << "\n" << std::endl;
			udpEcho.tx(inet_ntoa(rxDatagram.sin_addr), rxDatagram.sin_port, rxDatagram.payload, rxDatagram.payloadLen, s, us);
		}
	}

	udpEcho.closeSocket();
}