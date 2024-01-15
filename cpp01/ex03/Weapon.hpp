#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType() const;
		const std::string getType_() const;
		void setType(std::string type);
};

#endif