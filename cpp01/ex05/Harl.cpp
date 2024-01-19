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
	if (level == "DEBUG")
	{
		void (Harl::*ptr)(void) = &Harl::debug;
		(this->*ptr)();
	}
	if (level == "INFO")
	{
		void (Harl::*ptr)(void) = &Harl::info;
		(this->*ptr)();
	}
	if (level == "WARNING")
	{
		void (Harl::*ptr)(void) = &Harl::warning;
		(this->*ptr)();
	}
	if (level == "ERROR")
	{
		void (Harl::*ptr)(void) = &Harl::error;
		(this->*ptr)();
	}
}