#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <ctime>
# include <algorithm>
# include <iterator>
# include <cstdlib>
# include <climits>
#include <iomanip>
class PmergeMe
{
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;

        // Sorting functions per container (Ford-Johnson)
        void                _sortVector(std::vector<int>& vec);
        void                _sortDeque(std::deque<int>& deq);

        // Helper to generate Jacobsthal insertion sequence
        std::vector<size_t> _generateJacobsthal(size_t n);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        bool    parseInput(int argc, char** argv);
        void    execute();
};

#endif