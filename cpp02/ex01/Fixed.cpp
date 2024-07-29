

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): nb(other.nb) {
    std::cout << "Copy constructor called" << std::endl;
};

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    nb = value << fbits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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