#include "ft_sed.hpp"


int main (int ac, char **av)
{
	File file;
	// file.loadContent(my_file);
	// std::cout << file.getContent();
	if (ac == 4 )
	{
		std::string s = av[2];
		if (!s.length())
			std::cout << "there is no thing to replace" << std::endl;
		else
			file.ft_sed(av[1], av[2], av[3]);
	}
	else
		std::cout << "not enough argument";

	// std::cout << "data writed to the file\n" ;
}