#include "RPN.hpp"

int main(int ac, char **av)
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
        if (!processToken(str, token))
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