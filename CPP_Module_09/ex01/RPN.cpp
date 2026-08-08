#include "RPN.hpp"

bool isNumber(const std::string &str)
{
    if (str.size() == 1 && std::isdigit(str[0]))
        return true;

    if (str.size() == 2 &&
        (str[0] == '+' || str[0] == '-') &&
        std::isdigit(str[1]))
        return true;

    return false;
}

bool applyOperation(std::stack<double> &token, char op)
{
    if (token.size() < 2)
    {
        std::cout << "error\n";
        return false;
    }

    double nbr2 = token.top();
    token.pop();

    double nbr1 = token.top();
    token.pop();

    double result;

    if (op == '+')
        result = nbr1 + nbr2;

    else if (op == '-')
        result = nbr1 - nbr2;

    else if (op == '*')
        result = nbr1 * nbr2;

    else if (op == '/')
    {
        if (nbr2 == 0)
        {
            std::cerr << "Error: division by zero" << std::endl;
            return false;
        }

        result = nbr1 / nbr2;
    }

    else
    {
        std::cout << "error\n";
        return false;
    }

    token.push(result);
    return true;
}

bool processToken(const std::string &str, std::stack<double> &token)
{
    if (str.size() > 2)
    {
        std::cout << "error\n";
        return false;
    }

    if (isNumber(str))
    {
        token.push(std::strtod(str.c_str(), NULL));
        return true;
    }

    if (str.size() == 1 &&
        (str[0] == '+' ||
         str[0] == '-' ||
         str[0] == '*' ||
         str[0] == '/'))
    {
        return applyOperation(token, str[0]);
    }

    std::cout << "error\n";
    return false;
}