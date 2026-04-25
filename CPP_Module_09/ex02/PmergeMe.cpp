#include "PmergeMe.hpp"

bool fill_containers(int ac, char **av, std::vector<int>& vec, std::deque<int>& deq)
{
    for (int i = 1; i < ac; i++)
    {
        char *endptr;
        long x = std::strtol(av[i], &endptr, 10);
        if (*endptr != '\0' || av[i][0] == '\0')
        {
            std::cerr << "Error: Not a valid number" << std::endl;
            return false;
        }
        if (x < 0 || x > INT_MAX)
        {
            std::cerr << "Error: Number out of range" << std::endl;
            return false;
        }
        vec.push_back(static_cast<int>(x));
        deq.push_back(static_cast<int>(x));
    }
    return true;
}