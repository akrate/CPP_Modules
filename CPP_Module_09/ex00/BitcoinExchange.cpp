#include "BitcoinExchange.hpp"

std::map<std::string,double> read_file_from_data()
{
    std::ifstream filedata("data.csv");
    if (!filedata.is_open())
    {
        std::cout << "Error: could not open file data.\n";
        exit(1);
    }
    std::string line;
    std::getline(filedata,line,'\n');
    std::map<std::string,double> data;
    while(std::getline(filedata,line,'\n'))
    {
        std::stringstream tmp(line);
        std::string date,price;
        if (std::getline(tmp,date,',') && std::getline(tmp,price))
            data[date] = strtod(price.c_str(),NULL);
    }
    filedata.close(); 
    return data;
}

bool open_file(std::ifstream &file, std::string filename)
{
    file.open(filename.c_str());
    if(!file.is_open())
    {
        std::cout << "Error: could not open file.\n";
        return false;
    }
    return true;
}

int bitcoin_exchange(std::string file_input, const std::map<std::string,double> &data)
{
    std::ifstream fileinput;
    if (!open_file(fileinput,file_input))  
        return 1;
    std::string line;
    std::getline(fileinput,line,'\n');
    while (std::getline(fileinput, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos);
        
        size_t last = date.find_last_not_of(" ");
        if (last != std::string::npos)
            date.erase(last + 1);
        
        size_t first = date.find_first_not_of(" ");
        if (first != std::string::npos)
            date.erase(0, first);
            
        std::string valStr = line.substr(pipePos + 1);
        char* endptr;
        double val = strtod(valStr.c_str(), &endptr);

        if (val < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::const_iterator it = data.lower_bound(date);

        if (it != data.end() && it->first == date) {
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        } 
        else if (it != data.begin()) {
            --it; 
            std::cout << date << " => " << val << " = " << val * it->second << std::endl;
        } 
        else {
            std::cout << "Error: bad input => " << date << std::endl;
        }
    }
    fileinput.close(); 
    return 0; 

}