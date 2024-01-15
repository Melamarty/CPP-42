#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
		std::string _type;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce();
		void set_name(std::string name);
		std::string get_name();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
#endif
