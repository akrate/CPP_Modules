#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int size;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();

        template <typename Ve>
        void addrange(Ve begin,Ve end)
        {
            if (std::distance(begin,end) +  numbers.size() > size)
                throw std::overflow_error("Span: not enough space to add range");
            numbers.insert(numbers.end(),begin,end);
        }
        void addNumber(int num);
        int shortestSpan();
        size_t longestSpan();
};

#endif