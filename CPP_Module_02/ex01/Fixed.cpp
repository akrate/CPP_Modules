#include "Fixed.hpp"
Fixed::Fixed(const int value)
{  
    std::cout << "Int constructor called" << std::endl;
    x = value << nbr;

}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    x = roundf(value * (1 << nbr));
}
Fixed::Fixed() : x(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        x = other.x;
    return *this;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
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