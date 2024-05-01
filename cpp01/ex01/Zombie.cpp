#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Contsructor called Zombie" << std::endl;;
	this->_name = "default";
}

Zombie::Zombie(std::string name)
{
	std::cout << "Contsructor called Zombie" << std::endl;;
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": is dead." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name <<  ": Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string Zombie::get_name()
{
	return this->_name;
}