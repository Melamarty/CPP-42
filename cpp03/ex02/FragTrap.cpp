#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (energy_points > 0 && hit_points > 0) {
		energy_points--;
		std::cout << "FragTrap " << name << " ferociously attacks " << target 
				<< ", causing " << attack_damage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << name << " has no energy or hit points left to attack!" << std::endl;
	}
}


void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name <<  " hi fives guyes" << std::endl;
}

FragTrap::FragTrap()
{
	this->name = "default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 30;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this == &other) {
		return *this;
	}
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.attack_damage;
	this->attack_damage = other.attack_damage;

	return *this;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
}

