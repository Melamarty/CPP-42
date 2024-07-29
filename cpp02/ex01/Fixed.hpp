#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
    private:
        int nb;
        static const int fbits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int value);
        Fixed(const float value);
        Fixed &operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt() const;
        float toFloat () const;
        ~Fixed();
        friend std::ostream& operator<<(std::ostream& out, const Fixed& fp);
};

#endif