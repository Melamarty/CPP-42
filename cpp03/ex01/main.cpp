#include "ScavTrap.hpp"

int main() {
	ScavTrap scavtrap("Scavy");

	scavtrap.attack("target A");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(20);

	scavtrap.guardGate();

	scavtrap.attack("target B");
	scavtrap.takeDamage(50);
	scavtrap.beRepaired(40);

	return 0;
}
