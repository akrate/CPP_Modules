#include "tool.hpp"

int main(int ac,char **av)
{
    if (ac != 4)
    {
        std::cout << " program that takes three parameters\n";
        return 1;
    }
    return open_end_read(av[1], av[2], av[3]);
}