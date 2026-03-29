#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other){(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){(void)other;return *this;}
ScalarConverter::~ScalarConverter(){}


static bool is_char(const std::string& str)
{
    if (str.length() != 1)
        return false;
    return std::isprint(static_cast<unsigned char>(str[0]));
}
static bool is_int(const std::string str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
static bool is_float(const std::string str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
        {
            if (i == 0)
                return false;
            i++;
            while (str[i])
            {
                if (str[i] == 'f')
                    count++;
                if (!isdigit(str[i]) && str[i] != 'f')
                    return false;
                i++;
            }
            if (count != 1)
                return false;
            return true;
        }
    }
    return false;
}
static bool is_double(const std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
        {
            if (i == 0)
                return false;
            i++;
            while (str[i])
            {
                if (!isdigit(str[i]))
                    return false;
                i++;
            }
            return true; 
        }
    }
    return false;
}
void print_char(double val)
{
    std::cout << "char: ";
    char c = static_cast<char>(val);
    if (!isprint(c))
    {
        std::cout << "Non displayable\n";
        return ;
    }
    std::cout << "\'" << static_cast<char>(val) << "\'\n"; 
    
}
void print_int(double val)
{
    std::cout << "int: ";
    if (val > std::numeric_limits<int>::max() ||
        val < std::numeric_limits<int>::min())
    {
        std::cout << "impossible\n";
        return ;
    }
    std::cout << static_cast<int>(val) << std::endl; 
}
void print_float(double val)
{
    std::cout << "float: " << std::fixed 
        << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
}
void print_double(double val)
{
    std::cout << "double: " << std::fixed 
        << std::setprecision(1) << val << std::endl;
}
void special_case(const std::string& str)
{
    std::string floatStr = "";
    std::string doubleStr = "";

    if (str == "nan" || str == "nanf")
    {
        floatStr = "nanf";
        doubleStr = "nan";
    } else if (str == "+inf" || str == "+inff")
    {
        floatStr = "+inff";
        doubleStr = "+inf";
    } else if (str == "-inf" || str == "-inff")
    {
        floatStr = "-inff";
        doubleStr = "-inf";
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << floatStr << std::endl;
    std::cout << "double: " << doubleStr << std::endl;
}
void ScalarConverter::convert(const std::string& str)
{
    double val;
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || 
    str == "-inf" || str == "-inff") 
    {
        special_case(str);
        return ;
    }
    if(is_int(str) ==  true)
        val = static_cast<double>(std::atoi(str.c_str()));
    else if (is_char(str) == true)
    {
        val = static_cast<double>(str[0]);
    }
    else if (is_float(str) == true)
    {
        val = static_cast<double>(std::atof(str.c_str()));
        
    }
    else if(is_double(str) ==  true)
    {
        val = strtod(str.c_str(), NULL);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible"<< std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    print_char(val);
    print_int(val);
    print_float(val);
    print_double(val);
}