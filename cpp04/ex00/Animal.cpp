#include "Animal.hpp"

Animal::Animal(): type("default")
{
	std::cout << "default Constructor for Animal called" << std::endl;
}
Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << "copy Constructor for Animal called" << std::endl;
}


Animal& Animal::operator=(const Animal &other)
{
	if (this == &other)
	{
		return *this;
	}
	std::cout << "copy assignment operator for Animal called" << std::endl;
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor for Animal called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}