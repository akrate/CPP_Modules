#include "RPN.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout << "error argument\n";
        return 1;
    }
    std::stack<double> token;
    std::stringstream splt(av[1]);
    std::string str;
    while (splt >> str)
    {
        if (str.size() > 2)
        {
            std::cout << "error\n";
            return 1;
        }
        if (str.size() == 2 
            && (str[0] == '+' || str[0] == '-') 
                && std::isdigit(str[1]))
        {
            token.push(std::strtod(str.c_str(),NULL));
            continue;
        }   
        if (str.size() == 1 && std::isdigit(str[0]))
        {
            token.push(std::strtod(str.c_str(),NULL));
            continue;
        }
        if (str.size() == 1)
        {
            double result;
            double nbr1;
            double nbr2;
            if (token.size() < 2)
            {
                std::cout << "error\n";
                return 1;
            }
            if (str[0] == '+' )
            {
                nbr2 = token.top();
                token.pop();
                nbr1 = token.top();
                token.pop();
                result = nbr1 + nbr2;
                token.push(result);
                continue;
            }
            if (str[0] == '-' )
            {
                nbr2 = token.top();
                token.pop();
                nbr1 = token.top();
                token.pop();
                result = nbr1 - nbr2;
                token.push(result);
                continue;
            }
            if (str[0] == '/' )
            {
                nbr2 = token.top();
                token.pop();
                nbr1 = token.top();
                token.pop();
                if (nbr2 == 0)
                {
                    std::cerr << "Error: division by zero" << std::endl;
                    return 1;
                }
                result = nbr1 / nbr2;
                token.push(result);
                continue;
            }
            if (str[0] == '*' )
            {
                nbr2 = token.top();
                token.pop();
                nbr1 = token.top();
                token.pop();
                result = nbr1 * nbr2;
                token.push(result);
                continue;
            }
        }
        std::cout << "error\n";
        return 1;
    }
    if (token.size() != 1)
    {
        std::cout << "error\n";
        return 1;
    }
    std::cout << token.top() << std::endl;
    return 0;
}