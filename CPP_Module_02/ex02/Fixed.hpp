#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int x;
        static const int nbr = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);

        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        static const Fixed& max(const Fixed& other1,const Fixed& other2);
        static Fixed& max(Fixed& other1,Fixed& other2);
        static const Fixed& min(const Fixed& other1,const Fixed& other2);
        static Fixed& min(Fixed& other1,Fixed& other2);
};
std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif