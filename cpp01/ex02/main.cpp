#include <iostream>

int main ()
{
	std::string	str = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "adress of the str          : " << &str << std::endl;
	std::cout << "addresse held by stringPTR : " << stringPTR << std::endl;
	std::cout << "addresse held by stringREF : " << &stringREF << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "str value                  : " << str << std::endl;
	std::cout << "value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "value pointed by stringREF : " << stringREF << std::endl;
}