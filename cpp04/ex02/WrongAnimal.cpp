#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("default")
{
	std::cout << "default Constructor for WrongAnimal called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << "copy Constructor for WrongAnimal called" << std::endl;
}


WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
	{
		return *this;
	}
	std::cout << "copy assignment operator for WrongAnimal called" << std::endl;
	this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor for WrongAnimal called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}