#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){}


HumanB::~HumanB()
{
	// destructor
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