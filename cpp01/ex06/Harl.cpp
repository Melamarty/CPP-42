#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "this message from debuging function" << std::endl;
}
void Harl::info(void)
{
	std::cout << "this message from info function" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "this message from warning function" << std::endl;
}
void Harl::error(void)
{
	std::cout << "this message from error function" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*fns[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl harl;
	int i;
	for (i = 0 ; i < 4; i++)
	{
		if (level == lvls[i])
			break;
	}
	if (i == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	for (int j = i; j < 4; j++)
	{
		(harl.*fns[j])();
	}
}