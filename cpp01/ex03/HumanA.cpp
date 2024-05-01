#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& wp) : _name(name), _wp(wp) {

	std::cout << "Constructor called HumanA" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Destructor called HumanA" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_wp.getType() << std::endl;	
}