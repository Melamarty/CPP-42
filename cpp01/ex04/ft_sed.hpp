#ifndef FT_SED_HPP
#define FT_SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class File
{
	private:
		std::string _content;
	public:
		void loadContent(std::fstream &file);
		std::string getContent();
		void ft_sed(std::string filename, std::string s1, std::string s2);
};

#endif
