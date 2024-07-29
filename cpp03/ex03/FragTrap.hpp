#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap& operator=(const FragTrap &other);
		FragTrap(const std::string &name);
		~FragTrap();
		void highFivesGuys(void);
		void attack(const std::string& target);
};

void hello();
#endif