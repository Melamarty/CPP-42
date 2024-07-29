#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "default Constructor for Brain called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100 ; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "copy Constructor for Brain called" << std::endl;
}


Brain& Brain::operator=(const Brain &other)
{
	if (this == &other)
	{
		return *this;
	}
	for (int i = 0; i < 100 ; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "copy assignment operator for Brain called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor for Brain called" << std::endl;
}