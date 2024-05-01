#include "Harl.hpp"

int main(int ac, char **av) {
	Harl obj;

	if (ac != 2)
	{
		std::cout << "./harlFilter LEVEl" << std::endl;
		return (1);
	}
	obj.complain(av[1]);
    return 0;
}
