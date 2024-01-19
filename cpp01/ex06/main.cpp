#include "Harl.hpp"

int main(int ac, char **av) {
	Harl obj;

	if (ac != 2)
	{
		std::cout << "./harlfilter LEVEl" << std::endl;
		return (1);
	}
	int i = 0;
	std::string arg = av[1];
	if (arg == "DEBUG")
		i = 1;
	if (arg == "INFO")
		i = 2;
	if (arg == "WARNING")
		i = 3;
	if (arg == "ERROR")
		i = 4;
	if (i == 0)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (0);
	}
	if (i <= 1)
		obj.complain("DEBUG");
	if (i <= 2)
		obj.complain("INFO");
	if (i <= 3)
		obj.complain("WARNING");
	if (i <= 4)
		obj.complain("ERROR");
    return 0;
}
