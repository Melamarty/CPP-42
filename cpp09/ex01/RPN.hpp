#pragma once

#include <iostream>

#include <vector>
#include <iterator>
#include <sstream>
#include <stack>

std::stack<std::string> parseNotation(const std::string &s);
std::string trim(const std::string &s);
std::vector<std::string> split(std::string s, char del);
void displayStack(std::stack<std::string> &stack);