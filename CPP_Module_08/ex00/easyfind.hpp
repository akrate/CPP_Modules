#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


template <typename T>
typename T::iterator easyfind(T &container,int type)
{
    typename T::iterator it = std::find(container.begin(),container.end(),type);
    if (it != container.end())
        return it;
    else
        throw std::runtime_error("Value not found in container");
}
#endif