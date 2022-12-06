#include "udp.h"

void echo(int localPortNum, long s, long us)
{
	udpSocket udpEcho;
	udpEcho.openSocket(localPortNum);

	bool listening = true;
	std::cout << "echoing...\n" << std::endl;
	datagram rxDatagram;
	while (listening == true)
	{
		int result = udpEcho.rx(rxDatagram, s, us);
		if (result > 0)
		{
			udpEcho.tx(inet_ntoa(rxDatagram.sin_addr), rxDatagram.sin_port, rxDatagram.payload, rxDatagram.payloadLen, s, us);
			std::cout << "echo" << std::endl;
		}
	}

	udpEcho.closeSocket();
}