#include "BitcoinExchange.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1;   
    }
    std::ifstream fileinput(av[1]);
    if (!fileinput.is_open())
    {
        std::cout << "Error: could not open file.\n";
        return 1;
    }
    std::ifstream filedata("data.csv");
    if (!filedata.is_open())
    {
        std::cout << "Error: could not open file data.\n";
        return 1;
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
    std::getline(fileinput,line,'\n');
    while (std::getline(fileinput,line,'\n'))
    {
        std::stringstream tmp(line);
        std::string date,val;
        if (std::getline(tmp,date,'|') && std::getline(tmp,val))
        {
            double pr = strtod(val.c_str(),NULL);
            std::map<std::string,double>::iterator tt = data.find(date);
            if (tt == data.end()){
                tt = data.lower_bound(date);
                 std::cout << date << "=>" << val << "=" 
                    << tt->second << std::endl;
            }else{

                std::cout << date << "=>" << val << "=" 
                << tt->second << std::endl;
            }
        }
        else   
            std::cout << "Error: bad input => " << line << std::endl;
    }
}