#include "Zombie.hpp"


int main ()
{
	Zombie *zombie = newZombie ("Zombie");
	zombie->announce();
	Zombie zombie2("Zombie2");
	zombie2.announce();
	delete zombie;
	randomChump("Zombie3");
}