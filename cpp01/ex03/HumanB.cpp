#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){
	std::cout << "Constructor called HumanB" << std::endl;
}


HumanB::~HumanB()
{
	std::cout << "Desstructor called HumanB" << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
	// delete _wp;
	_wp = &wp;
	// _wp = new Weapon(wp);
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_wp->getType() << std::endl;	
}