#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("oussama",1);
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        Bureaucrat a("oussama",1);
        std::cout << a << std::endl;
        a.decrement();
        std::cout << b << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
    return 0;
}