#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap& operator=(const ScavTrap &other);
		ScavTrap(const std::string &name);
		~ScavTrap();
		void guardGate();
		void attack(const std::string& target);
		
};

#endif