#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) {
		return *this;
	}
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.attack_damage;
	this->attack_damage = other.attack_damage;

	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.attack_damage;
	this->attack_damage = other.attack_damage;
}


ClapTrap::ClapTrap(const std::string& name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}
void ClapTrap::attack(const std::string& target)
{
	if (hit_points > 0 && energy_points > 0)
	{
		std::cout << "ClapTrap " << name << " attaks " << target << ", causing "
				  << attack_damage << " points of damage" << std::endl;
		energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	 if (hit_points > 0) {
			hit_points -= amount;
			if (hit_points < 0) hit_points = 0;
			std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		} else {
			std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
		}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points > 0 && energy_points > 0)
	{
		std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
		hit_points += amount;
		energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " has no energy or hit points left to be repaired!" << std::endl;
	}

}
