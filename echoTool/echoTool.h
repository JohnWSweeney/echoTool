#pragma once
#include <iostream>
#include <vector>

// start.cpp
void getInput(std::vector<std::string> &tokens);
void startEchoThread(std::vector<std::string> &tokens);
void selectThread(bool &running, std::vector<std::string> &tokens);
void start();

// udpFunctions.cpp
void echo(int localPortNum);