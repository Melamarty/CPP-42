#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name): ClapTrap (name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destroyed." << std::endl;
}


void ScavTrap::attack(const std::string& target) {
	if (energy_points > 0 && hit_points > 0) {
		energy_points--;
		std::cout << "ScavTrap " << name << " ferociously attacks " << target 
				<< ", causing " << attack_damage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << name << " has no energy or hit points left to attack!" << std::endl;
	}
}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}

ScavTrap::ScavTrap()
{
	this->name = "default";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other) {
		return *this;
	}
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.attack_damage;
	this->attack_damage = other.attack_damage;

	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.attack_damage;
	this->attack_damage = other.attack_damage;
}