#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(const std::string& name):  ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	FragTrap::hit_points = 100;
	ScavTrap::energy_points = 50;
	FragTrap::attack_damage = 20;
	std::cout << "DiamondTrap " << this->name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}
void	DiamondTrap::whoAmI( void ) {
	std::cout << "I am a DiamondTrap named " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
