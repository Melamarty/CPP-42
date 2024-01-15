#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon ()
{
	std::cout << "desstructor called" << std::endl;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string& Weapon::getType() const
{
	std::cout << "inside :" << &this->_type << std::endl;
	return this->_type;
}

const std::string Weapon::getType_() const
{
	std::cout << "inside2 :" << &this->_type << std::endl;
	return _type;
}