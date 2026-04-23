#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <climits>

template <typename T,typename Y>
void spilt_numbers(T& container,Y& source)
{
    int last = -1;
    if (source.size() % 2 == 1)
    {
        last = source.back();
        source.pop_back();
    }
    for (size_t i = 0;i < source.size();i += 2)
    {
        if (source[i] >= source[i +1])
        {
            container.push_back(std::make_pair(source[i],source[i+1]));
            
        }
        else
        {
            container.push_back(std::make_pair(source[i+1],source[i]));
        }
    }
    if (last != -1)
    {
        ;
    }
}
#endif