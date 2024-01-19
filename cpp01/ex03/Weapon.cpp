#include "Weapon.hpp"

Weapon::Weapon()
{
	this->_type = "default type";
}

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
	return this->_type;
}

const std::string Weapon::getType_() const
{
	return _type;
}