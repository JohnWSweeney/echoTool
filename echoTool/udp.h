#pragma once
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")

struct datagram
{
	IN_ADDR sin_addr;
	USHORT sin_port;
	int payloadLen;
	char payload[1472] = { 0 };
};

class udpSocket
{
public:
	int result = 0;
	SOCKET udpSocketServer;
	int socketReadStatus(SOCKET udpSocketServer, long s, long us);
	int socketWriteStatus(SOCKET udpSocketServer, long s, long us);
	void openSocket(int localPortNum);
	int rx(datagram& rxDatagram, long s, long us);
	void tx(const char* destIP, int destPortNum, const char *buf, int len, long s, long us);
	void closeSocket();
};

void echo(int localPortNum, long s, long us);