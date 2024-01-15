#include "Weapon.hpp"

int main()
{
	Weapon club = Weapon("new type");
	std::string &str1 = club.getType();
	std::string str2 = club.getType_();
	std::cout << &club.getType() << std::endl;
	// std::cout << &club.getType_() << std::endl;
	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanA bob("Bob", club);
	// 	bob.attack();
	// 	club.setType("some other type of club");
	// 	bob.attack();
	// }
	// {
	// 	Weapon club = Weapon("crude spiked club");
	// 	HumanB jim("Jim");
	// 	jim.setWeapon(club);
	// 	jim.attack();
	// 	club.setType("some other type of club");
	// 	jim.attack();
	// }
	// return 0;
}