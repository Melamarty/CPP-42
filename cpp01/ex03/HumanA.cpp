#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& wp) : _name(name), _wp(wp) {}

HumanA::~HumanA()
{
	// destructor
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_wp.getType() << std::endl;	
}