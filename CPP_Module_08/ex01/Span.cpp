#include "Span.hpp"

Span::Span()
{
    size = 0;
}
Span::Span(unsigned int n)
{
    size = n;
    numbers.reserve(n);
}
Span::Span(const Span &other)
{
    *this = other;
}
Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        size = other.size;
        numbers = other.numbers;
    }
    return *this;
}
Span::~Span()
{

}
void Span::addNumber(int num)
{
    if (numbers.size() < size)
    {
        numbers.push_back(num);
    }
    else 
    {
        throw std::overflow_error("Span: not enough space to add range");
    }
}
int Span::shortestSpan()
{
    if (numbers.size()  < 2 )
        throw std::runtime_error("not enough");
    std::sort(numbers.begin(),numbers.end());
    int minspan = __INT_MAX__;
    for (int i = 1;i < numbers.size();i++)
    {
        if ((numbers[i] - numbers[i -1]) < minspan)
            minspan = numbers[i] - numbers[i -1];
    }
    return minspan;
}
size_t Span::longestSpan()
{
    if (numbers.size()  < 2 )
        throw std::runtime_error("not enough");
    size_t max = *std::max_element(numbers.begin(),numbers.end());
    size_t min = *std::min_element(numbers.begin(),numbers.end());
    return max - min;
}