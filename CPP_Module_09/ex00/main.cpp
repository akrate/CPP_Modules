#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;   
    }
    
    std::map<std::string,double> data = read_file_from_data();
    return bitcoin_exchange(av[1],data);
}