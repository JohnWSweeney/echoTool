#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <Windows.h>

void getInput(std::vector<std::string> &tokens);
void startEchoThread(std::vector<std::string> &tokens);
void startMenu(bool &running, std::vector<std::string> &tokens);