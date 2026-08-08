#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

bool processToken(const std::string &str, std::stack<double> &token);
#endif