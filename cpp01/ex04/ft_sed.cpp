#include "ft_sed.hpp"

void File::loadContent(std::fstream &file)
{
	std::string line;
	std::string content;

	while (getline(file, line))
    {
		content += line;
        if (!file.eof())
            content += "\n";
    }
	this->_content = content;
}

std::string File::getContent()
{
	return this->_content;
}

void File::ft_sed(std::string filename, std::string s1, std::string s2)
{
	int	i = 0;
	int len = s1.length();
	std::fstream my_file(filename);
	std::string tmp;
	this->loadContent(my_file);
	std::string content = this->getContent();

	// std::cout << len << std::endl;
    if (!my_file.is_open())
    {
        std::cerr << "Error opening the file\n";
        exit (1);
    }
	while (i < content.length())
    {
        if (s1.compare(0, len, content.substr(i, len)) == 0)
        {
            tmp += s2; 
            i += len;
        }
        else
        {
            tmp += content[i];
            i++;
        }
    }
	// std::cout << tmp;
	my_file.close();

    // Reopen the file in truncation mode
    filename += ".replace";
    my_file.open(filename, std::ios::out | std::ios::trunc);
    if (!my_file.is_open())
    {
        std::cerr << "Error opening the file\n";
        exit (1);
    }

    my_file << tmp;  // Write the modified content to the file

    my_file.close();
}