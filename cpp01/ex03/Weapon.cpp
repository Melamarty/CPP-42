#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Constructor called Weapon" << std::endl;
	this->_type = "default type";
}

Weapon::Weapon(std::string type)
{
	std::cout << "Constructor called Weapon" << std::endl;
	this->_type = type;
}

Weapon::~Weapon ()
{
	std::cout << "Desstructor called Weapon" << std::endl;
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