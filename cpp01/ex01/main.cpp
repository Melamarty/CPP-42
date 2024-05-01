#include "Zombie.hpp"

int main ()
{
	Zombie* horde = NULL;
	horde = horde->zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	// randomChump("Zombie");
}