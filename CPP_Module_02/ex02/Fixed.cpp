#include "Fixed.hpp"
Fixed::Fixed(const int value)
{  
    x = value << nbr;
}
Fixed::Fixed(const float value)
{
    x = roundf(value * (1 << nbr));
}
Fixed::Fixed() : x(0)
{
}
Fixed::Fixed(const Fixed& other)
{
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        x = other.x;
    return *this;
}
Fixed::~Fixed()
{
}
int Fixed::getRawBits( void ) const
{
    return x;
}
void Fixed::setRawBits( int const raw )
{
    x = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)x / (1 << nbr);
}

int Fixed::toInt( void ) const
{
    return x /(1 << nbr);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj)
{
    out << obj.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const
{
    return x > other.x;
}

bool Fixed::operator<(const Fixed& other) const
{
    return x < other.x;
}

bool Fixed::operator==(const Fixed& other) const
{
    return x == other.x;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return x != other.x;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return x >= other.x;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return x <= other.x;
}

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed tmp;

    tmp.x = x + other.x;
    return tmp;
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed tmp;

    tmp.x = x - other.x;
    return tmp;
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed tmp;

    tmp.x = (x * other.x) >> nbr;
    return tmp;
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed tmp;

    tmp.x = (x << nbr) / other.x;
    return tmp;
}

Fixed Fixed::operator++()
{
   x++;
   return *this;
}
Fixed Fixed::operator--()
{
    x--;
   return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    x++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    x--;
    return tmp;
}
const Fixed& Fixed::max(const Fixed& other1,const Fixed& other2)
{
    if(other1.x > other2.x)
        return other1;
    else
        return other2;
}

Fixed& Fixed::max(Fixed& other1,Fixed& other2)
{
    if(other1.x > other2.x)
        return other1;
    else
        return other2;
}
const Fixed& Fixed::min(const Fixed& other1,const Fixed& other2)
{
    if(other1.x < other2.x)
        return other1;
    else
        return other2;
}

Fixed& Fixed::min(Fixed& other1,Fixed& other2)
{
    if(other1.x < other2.x)
        return other1;
    else
        return other2;
}
