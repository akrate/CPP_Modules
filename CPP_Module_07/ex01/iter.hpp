#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T , typename Y>
void iter(T* array, const size_t size, void (func)(Y&))
{
    if (!array)
    {
        std::cout << "this array is empty\n";
        return ;
    }
    if (!func)
    {
        std::cout << "this functio is null\n";
        return ;
    }
    for (size_t i = 0; i < size; i++)
    {
        func(array[i]);
    }

}
#endif
