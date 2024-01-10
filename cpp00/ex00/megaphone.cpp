#include <iostream>

int main (int ac, char **av)
{
	int i = 1;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	while (i < ac)
	{
		int j= 0;
		while (av[i][j])
		{
			std::cout << (char)std::toupper(av[i][j]);
			j++;
		}
		std::cout << " ";
		i++;
	}
}