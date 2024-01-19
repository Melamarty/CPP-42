#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &wp);
		~HumanB();
		void attack();
	private:
		std::string _name;
		Weapon *_wp;
};


# endif