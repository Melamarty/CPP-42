#include "Dog.hpp"

Dog::Dog(): type("Dog")
{
	b = new Brain();
	std::cout << "default Constructor for Dog called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
	this->b = other.b;
	std::cout << "copy Constructor for Dog called" << std::endl;
}


Dog& Dog::operator=(const Dog &other)
{
	if (this == &other)
	{
		return *this;
	}
	std::cout << "copy assignment operator for Dog called" << std::endl;
	this->type = other.type;
	this->b = other.b;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor for Dog called" << std::endl;
	delete b;
}

void Dog::makeSound() const
{
	std::cout << "hawhawhaw" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}