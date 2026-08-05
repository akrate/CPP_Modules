#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        this->_vec = rhs._vec;
        this->_deq = rhs._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseInput(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        if (arg.empty())
            return false;

        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(arg[j]))
                return false;
        }

        long val = std::atol(arg.c_str());
        if (val <= 0 || val > INT_MAX)
            return false;

        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    return !_vec.empty();
}

// Jacobsthal sequence generator for insertion ordering
int jacobSthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int prev2 = 0, prev1 = 1, curr = 0;
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

void PmergeMe::_sortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    // 1. Handle odd elements (struggler)
    bool has_struggler = (vec.size() % 2 != 0);
    int struggler_val = 0;
    
    if (has_struggler) {
        struggler_val = vec.back();
        vec.pop_back();
    }

    // 2. Pair elements and track structural pairs directly
    typedef std::pair<int, int> PairType;
    std::vector<PairType> pairs;

    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i + 1], vec[i])); // {winner, loser}
        else
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
    }

    // Sort pairs recursively based on winners
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].first);
    }

    // Recursive call on winners
    _sortVector(winners);

    // 3. Re-order pairs vector to match sorted winners order
    std::vector<PairType> sorted_pairs;
    for (std::vector<int>::iterator win_it = winners.begin(); win_it != winners.end(); ++win_it)
    {
        for (std::vector<PairType>::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first == *win_it)
            {
                sorted_pairs.push_back(*it);
                pairs.erase(it); // Erasing prevents duplicate mismatches
                break;
            }
        }
    }

    // 4. Build Main Chain & Losers list
    std::vector<int> mainChain;
    std::vector<int> losers;
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        mainChain.push_back(sorted_pairs[i].first);
        losers.push_back(sorted_pairs[i].second);
    }

    // 5. Insert first loser at the front
    if (!losers.empty()) {
        mainChain.insert(mainChain.begin(), losers[0]);
    }

    // 6. Jacobsthal Insertion Sequence
    int size = static_cast<int>(losers.size());
    int prev_end = 1;
    int k = 3;

    while (prev_end < size) {
        int curr_end = jacobSthal(k) - 1;
        if (curr_end >= size) 
            curr_end = size - 1;

        for (int j = curr_end; j >= prev_end; --j) {
            int val_to_insert = losers[j];
            int corresponding_winner = sorted_pairs[j].first;
            
            // Upper bound for binary search is the corresponding winner in mainChain
            std::vector<int>::iterator bound = std::find(mainChain.begin(), mainChain.end(), corresponding_winner);

            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, val_to_insert);
            mainChain.insert(pos, val_to_insert);
        }

        prev_end = curr_end + 1;
        k++;
    }

    // 7. Insert struggler if it existed
    if (has_struggler) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), struggler_val);
        mainChain.insert(pos, struggler_val);
    }

    vec = mainChain;
}

// Ford-Johnson implementation explicitly for std::deque
void PmergeMe::_sortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1)
        return;

    // 1. Handle odd elements (struggler)
    bool has_struggler = (deq.size() % 2 != 0);
    int struggler_val = 0;
    
    if (has_struggler) {
        struggler_val = deq.back();
        deq.pop_back();
    }

    // 2. Pair elements and track structural pairs directly
    typedef std::pair<int, int> PairType;
    std::deque<PairType> pairs;

    for (size_t i = 0; i < deq.size(); i += 2) {
        if (deq[i] < deq[i + 1])
            pairs.push_back(std::make_pair(deq[i + 1], deq[i])); // {winner, loser}
        else
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }

    // Sort pairs recursively based on winners
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i) {
        winners.push_back(pairs[i].first);
    }

    // Recursive call on winners
    _sortDeque(winners);

    // 3. Re-order pairs deque to match sorted winners order
    std::deque<PairType> sorted_pairs;
    for (std::deque<int>::iterator win_it = winners.begin(); win_it != winners.end(); ++win_it) {
        for (std::deque<PairType>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->first == *win_it) {
                sorted_pairs.push_back(*it);
                pairs.erase(it); // Erasing prevents duplicate mismatches
                break;
            }
        }
    }

    // 4. Build Main Chain & Losers list
    std::deque<int> mainChain;
    std::deque<int> losers;
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        mainChain.push_back(sorted_pairs[i].first);
        losers.push_back(sorted_pairs[i].second);
    }

    // 5. Insert first loser at the front
    if (!losers.empty()) {
        mainChain.insert(mainChain.begin(), losers[0]);
    }

    // 6. Jacobsthal Insertion Sequence
    int size = static_cast<int>(losers.size());
    int prev_end = 1;
    int k = 3;

    while (prev_end < size) {
        int curr_end = jacobSthal(k) - 1;
        if (curr_end >= size) 
            curr_end = size - 1;

        for (int j = curr_end; j >= prev_end; --j) {
            int val_to_insert = losers[j];
            int corresponding_winner = sorted_pairs[j].first;
            
            // Upper bound for binary search is the corresponding winner in mainChain
            std::deque<int>::iterator bound = std::find(mainChain.begin(), mainChain.end(), corresponding_winner);

            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), bound, val_to_insert);
            mainChain.insert(pos, val_to_insert);
        }

        prev_end = curr_end + 1;
        k++;
    }

    // 7. Insert struggler if it existed
    if (has_struggler) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), struggler_val);
        mainChain.insert(pos, struggler_val);
    }

    deq = mainChain;
}

void PmergeMe::execute()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
    }
    std::cout << std::endl;

    clock_t startVec = clock();
    _sortVector(_vec);
    clock_t endVec = clock();
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

    clock_t startDeq = clock();
    _sortDeque(_deq);
    clock_t endDeq = clock();
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i)
    {
        std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);

std::cout << "Time to process a range of " << _vec.size() 
          << " elements with std::vector : " << timeVec << " us" << std::endl;
std::cout << "Time to process a range of " << _deq.size() 
          << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}