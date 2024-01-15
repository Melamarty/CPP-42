#include "Zombie.hpp"

void f()
{
	system("leaks zombie");
}

int main ()
{
	atexit (f);
	Zombie* horde = NULL;
	horde = horde->zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	// randomChump("Zombie");
}