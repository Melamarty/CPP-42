#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange created\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bt)
{
    (void)bt;
    std::cout << "BitcoinExchange copied\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bt)
{
    (void)bt;
    std::cout << "BitcoinExchange assigned\n";
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destroyed\n";
}

void BitcoinExchange::readData(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("could not open the file.");
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::vector <std::string> tokens = split(line, ',');
        std::string date = tokens[0];
        double rate = std::strtod(tokens[1].c_str(), 0);
        data[date] = rate;    
    }
    file.close();
}


void BitcoinExchange::readInput(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("could not open the file.");
    std::getline(file, line);
    std::vector <std::string> title = split(line, '|');
    if (title.size() != 2 || title[0] != "date" || title[1] != "value")
        throw std::runtime_error("ivalid input format");
    while (std::getline(file, line))
    {
        std::vector <std::string> tokens = split(line, '|');
        if (tokens.size() != 2)
            std::cout << "Error: bad input => " << line;
        else
        {
            std::string date = tokens[0];
            double rate = std::strtod(tokens[1].c_str(), 0);
            std::string err = validDate(date);
            if (!err.empty())
                std::cout << "Error: " << err;
            else if (rate > 1000)
                std::cout << "Error: too large number.";
            else if (rate < 0)
                std::cout << "Error: not a positive number.";
            else if (!isDouble(tokens[1]))
                std::cout << "Erorr: bad rate => " << tokens[1];
            else
                getBtc(date, rate);
        }
        std::cout << std::endl;
    }
    file.close();
}

void BitcoinExchange::displayData()
{
    std::map<std::string, double>::iterator it;
    for (it = data.begin(); it != data.end(); ++it)
    {
        std::cout << it->first << ",   " << it->second << std::endl;
    }
}

void BitcoinExchange::displayInput()
{
    std::map<std::string, double>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        std::cout << it->first << "  .|.  " << it->second << std::endl;
    }
}

void BitcoinExchange::getBtc(std::string &date, double &rate)
{
    std::map <std::string, double>::reverse_iterator it;
    for (it = data.rbegin(); it != data.rend(); ++it)
    {
        if (compare_dates(it->first, date) <= 0)
        {
            std::cout << it->first << " => " << it->second * rate;
            break;
        }
    }
}

/*==========================================================*/
/*      utils     */

int isDigit(const std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return (0);
    }
    return 1;
}

bool checkToken(std::string token)
{
    if (!isDigit(token) || token.length() > 4)
        return 1;
    double d = std::strtod(token.c_str(), 0);
    if (d <= 0)
        return 1;
    return 0;
}

std::string validDate(std::string &date)
{
    std::vector <std::string > tokens= split(date, '-');
    if (tokens.size() != 3)
        return "invalid date format";
    std::vector < std::string>::iterator it;
    for (it = tokens.begin(); it != tokens.end(); ++it)
    {
        if (checkToken(*it))
            return ("ivalid date token");
    }
    return "";
}


bool isDouble(const std::string &s)
{
    char *end = NULL;
    std::strtod(s.c_str(), &end);
    
    std::string res = end;
    return (res.empty());
}


std::string trim(const std::string &s)
{
    size_t start = 0;
    size_t end = s.length();

    while (start < end && s[start] == ' ') {
        ++start;
    }

    while (end > start && (s[end - 1] == ' ')) {
        --end;
    }

    return s.substr(start, end - start);
}

std::vector<std::string> split(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    std::vector <std::string> tokens;

    while (!ss.eof())
    {
        std::getline(ss, word, del);
        tokens.push_back(trim(word));
    }
    return tokens;
}

int compare_dates(const std::string &date1, const std::string &date2)
{
    std::vector <std::string> t1 = split(date1 , '-');
    std::vector <std::string> t2 = split(date2 , '-');
    if (std::strtod(t1[0].c_str(), 0) < std::strtod(t2[0].c_str(), 0))
        return (-1);
    else if (std::strtod(t1[0].c_str(), 0) > std::strtod(t2[0].c_str(), 0))
        return (1);
    
    if (std::strtod(t1[1].c_str(), 0) < std::strtod(t2[1].c_str(), 0))
        return (-1);
    else if (std::strtod(t1[1].c_str(), 0) > std::strtod(t2[1].c_str(), 0))
        return (1);

    if (std::strtod(t1[2].c_str(), 0) < std::strtod(t2[2].c_str(), 0))
        return (-1);
    else if (std::strtod(t1[2].c_str(), 0) > std::strtod(t2[2].c_str(), 0))
        return (1);
    
    return (0);
    return (0);
}