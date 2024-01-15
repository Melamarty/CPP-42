#include "Zombie.hpp"

void f()
{
	system("leaks zombie");
}

int main ()
{
	// atexit (f);
	Zombie *zombie = newZombie ("Zombie");
	zombie->announce();
	Zombie zombie2("Zombie2");
	zombie2.announce();
	delete zombie;
	// randomChump("Zombie");
}