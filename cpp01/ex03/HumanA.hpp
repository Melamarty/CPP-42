// #ifndef HUMANA_HPP
// # define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& wp);
		~HumanA();
		void attack();
	private:
		std::string _name;
		Weapon &_wp;

};

// Constructor definition
// HumanA::HumanA(const std::string& name, const Weapon& weapon) : name(name), weapon(weapon) {}

// # endif