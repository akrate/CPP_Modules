#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::map<std::string,double> read_file_from_data();
int bitcoin_exchange(std::string file_input, const std::map<std::string,double> &data);
#endif