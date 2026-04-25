#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac == 1) return 1;

    std::vector<int> v;
    std::deque<int> d;
    if (!fill_containers(ac, av, v, d))
        return 1;

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";

    std::cout << std::endl;
    ford_johnson_sort(v);
    ford_johnson_sort(d);

    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << std::endl;
}