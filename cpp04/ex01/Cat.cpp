#include "Cat.hpp"

Cat::Cat(): type("Cat")
{
	b = new Brain ();
	std::cout << "default Constructor for Cat called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	this->b = other.b;
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
	this->b = other.b;
	return *this;
}

Cat::~Cat()
{
	delete b;
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