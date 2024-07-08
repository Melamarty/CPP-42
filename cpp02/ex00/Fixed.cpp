#include "Fixed.hpp"

Fixed::Fixed()
{
    this->setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): nb(other.nb) {
    std::cout << "Copy constructor called" << std::endl;
};

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