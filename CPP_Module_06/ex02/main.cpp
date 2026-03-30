#include "Identify.hpp"

int main()
{
    srand(time(NULL));
    Base* ptr =   generate();

    std::cout << "identify by pointer: ";
    identify(ptr);

    std::cout << "identify by reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}