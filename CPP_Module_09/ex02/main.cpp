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
int main(int ac,char **av)
{
    if (ac == 1)
    {
        std::cerr << "Error\n";
        return 1;
    }
    std::vector<int> v;
    std::deque<int> d;
    if (!fill_containers(ac,av,v,d))
        return 1;
    std::vector<std::pair<int,int> > vec;
    std::deque<std::pair<int,int> > deq;
    spilt_numbers<std::vector<std::pair<int,int> > , std::vector<int> >(vec,v);
    spilt_numbers<std::deque<std::pair<int,int> > , std::deque<int> >(deq,d);
    std::vector<std::pair<int, int> >::iterator it = vec.begin();
    for (;it != vec.end();it++)
    {
        std::cout << it->first << ", " << it->second << std::endl;
    }
}