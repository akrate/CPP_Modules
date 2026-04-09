#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T> class Array
{
    private:
        T* data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array& other);
        Array& operator=(const Array& other);
        T& operator[](unsigned int index) const;
        ~Array();
        unsigned int size() const;
};
#include "Array.tpp"
#endif