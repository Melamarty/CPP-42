#include "ft_sed.hpp"


int main (int ac, char **av)
{
	File file;

	// file.loadContent(my_file);
	// std::cout << file.getContent();
	if (ac == 4 )
		file.ft_sed(av[1], av[2], av[3]);
	else
		std::cout << "not enough argument";

	// std::cout << "data writed to the file\n" ;
}