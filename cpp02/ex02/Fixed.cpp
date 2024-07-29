#include "Fixed.hpp"

Fixed::Fixed()
{
    this->setRawBits(0);
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): nb(other.nb) {
    // std::cout << "Copy constructor called" << std::endl;
};

Fixed::Fixed(const int value)
{
    nb = value << fbits;
}

Fixed::Fixed(const float value)
{
    float tmp = static_cast<float>(value) * (1 << fbits);
    nb = static_cast<int>(std::roundf(tmp));
}


int Fixed::toInt() const
{
    return nb >> fbits;
}

float Fixed::toFloat () const
{
    return static_cast<float>(nb) / (1 << fbits);
}

// operators
bool Fixed::operator>(const Fixed& other) const
{
    return nb > other.nb;
}
bool Fixed::operator<(const Fixed& other) const
{
    return nb < other.nb;
}
bool Fixed::operator>=(const Fixed& other) const
{
    return nb >= other.nb;
}
bool Fixed::operator<=(const Fixed& other) const
{
    return nb <= other.nb;
}
bool Fixed::operator==(const Fixed& other) const
{
    return nb == other.nb;
}
bool Fixed::operator!=(const Fixed& other) const
{
    return nb != other.nb;
}



Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed (this->toFloat() - other.toFloat());
}
Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed (this->toFloat() + other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed (this->toFloat() * other.toFloat());
    // long long result = static_cast<long long>(nb) * other.nb;
    // return bool(static_cast<int>(result >> fbits));
}
Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed (this->toFloat() - other.toFloat());
}


Fixed& Fixed::min (Fixed &a, Fixed &b)
{
   return  (a.nb < b.nb) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.nb < b.nb) ? a : b;
}
Fixed& Fixed::max (Fixed &a, Fixed &b)
{
   return  (a.nb > b.nb) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.nb > b.nb) ? a : b;
}

Fixed& Fixed::operator++()
{
    nb += 1;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    nb += 1;
    return tmp;
}
Fixed& Fixed::operator--()
{
    nb -= 1;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    nb -= 1;
    return tmp;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        nb = other.nb;
    }
    return *this;
}

int Fixed::getRawBits (void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->nb);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "" << std::endl;
    this->nb = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fp) {
    out << fp.toFloat();
    return out;
}