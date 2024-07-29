#include "ClapTrap.hpp"


int main() {
	ClapTrap ClapTrap("Clappy");

	ClapTrap.attack("target A");
	ClapTrap.takeDamage(3);
	ClapTrap.beRepaired(4);

	ClapTrap.attack("target B");
	ClapTrap.takeDamage(8);
	ClapTrap.beRepaired(2);

	ClapTrap.attack("target C");
	ClapTrap.takeDamage(1);
	ClapTrap.beRepaired(5);

	ClapTrap.takeDamage(50);
	ClapTrap.attack("target D");

	return 0;
}
