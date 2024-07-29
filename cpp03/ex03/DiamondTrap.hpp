#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap(const std::string& name);
		~DiamondTrap();
		using ScavTrap::attack;
		void   whoAmI( void );
};

#endif