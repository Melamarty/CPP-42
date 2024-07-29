#include "Cat.hpp"

Cat::Cat(): type("Cat")
{
	std::cout << "default Constructor for Cat called" << std::endl;
}
Cat::Cat(const Cat &other)
{
	this->type = other.type;
	std::cout << "copy Constructor for Cat called" << std::endl;
}


Cat& Cat::operator=(const Cat &other)
{
	if (this == &other)
	{
		return *this;
	}
	std::cout << "copy assignment operator for Cat called" << std::endl;
	this->type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor for Cat called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miawwwwwww" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}