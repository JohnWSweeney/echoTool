#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <WinSock2.h>

void startEchoThread(std::vector<std::string> &tokens);
void startServerThread(std::vector<std::string> &tokens);
void startSessionThread(SOCKET socket);