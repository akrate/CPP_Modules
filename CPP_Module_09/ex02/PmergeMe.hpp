#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>

template <typename T, typename Y>
void Pairing_numbers(T& container, Y& source, int &last)
{
    last = -1;
    if (source.size() % 2 == 1) {
        last = source.back();
        source.pop_back();
    }
    for (size_t i = 0; i < source.size(); i += 2) {
        if (source[i] >= source[i + 1])
            container.push_back(std::make_pair(source[i], source[i + 1]));
        else
            container.push_back(std::make_pair(source[i + 1], source[i]));
    }
}

template <typename Container>
void merge_pairs(Container& cont, const Container& left, const Container& right)
{
    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i].second <= right[j].second) cont[k++] = left[i++];
        else cont[k++] = right[j++];
    }
    while (i < left.size()) cont[k++] = left[i++];
    while (j < right.size()) cont[k++] = right[j++];
}

template <typename Container>
void recursive_sort(Container& cont)
{
    if (cont.size() <= 1) return;
    size_t mid = cont.size() / 2;
    Container left(cont.begin(), cont.begin() + mid);
    Container right(cont.begin() + mid, cont.end());
    recursive_sort(left);
    recursive_sort(right);
    merge_pairs(cont, left, right);
}

template <typename MainContainer, typename PendingContainer, typename PairContainer>
void extract_chains(const PairContainer& sorted_pairs, MainContainer& main, PendingContainer& pending, int last)
{
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        main.push_back(sorted_pairs[i].second);
        pending.push_back(sorted_pairs[i].first);
    }
    if (last != -1) pending.push_back(last);
}

std::vector<int> generate_jacobsthal(int n) {
    std::vector<int> jacob;
    int j0 = 0, j1 = 1;
    jacob.push_back(j0);
    jacob.push_back(j1);
    while (jacob.back() < n) {
        int next = jacob.back() + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}

void insert_pending_to_main(std::vector<int>& main_chain, const std::vector<int>& pending_chain) {
    if (pending_chain.empty()) return;
    std::vector<int> jacob = generate_jacobsthal(pending_chain.size());
    size_t prev_jacob = 1;
    for (size_t i = 2; i < jacob.size(); ++i) {
        int current_jacob = jacob[i];
        for (int j = current_jacob - 1; j >= (int)prev_jacob; --j) {
            if (j < (int)pending_chain.size()) {
                std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[j]);
                main_chain.insert(it, pending_chain[j]);
            }
        }
        prev_jacob = current_jacob;
    }
}

template <typename Container>
void ford_johnson_sort(Container& source) {
    int last = -1;
    std::vector<std::pair<int, int> > pairs; 
    
    Pairing_numbers(pairs, source, last);
    recursive_sort(pairs);
    
    Container main_chain;
    std::vector<int> pending_chain;
    extract_chains(pairs, main_chain, pending_chain, last);
    
    if (!pending_chain.empty()) {
        main_chain.insert(main_chain.begin(), pending_chain[0]);
        pending_chain.erase(pending_chain.begin());
    }
    
    std::vector<int> main_vec(main_chain.begin(), main_chain.end());
    insert_pending_to_main(main_vec, pending_chain);
    
    source.assign(main_vec.begin(), main_vec.end());
}
bool fill_containers(int ac, char **av, std::vector<int>& vec, std::deque<int>& deq);

#endif