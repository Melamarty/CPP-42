#include "WrongCat.hpp"

WrongCat::WrongCat(): type("WrongCat")
{
	std::cout << "default Constructor for WrongCat called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "copy Constructor for WrongCat called" << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
	{
		return *this;
	}
	std::cout << "copy assignment operator for WrongCat called" << std::endl;
	this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor for WrongCat called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miawwwwwww" << std::endl;
}

std::string WrongCat::getType() const
{
	return this->type;
}