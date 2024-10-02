#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "BitcoinExchange created\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bt)
{
    (void)bt;
    // std::cout << "BitcoinExchange copied\n";
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bt)
{
    (void)bt;
    // std::cout << "BitcoinExchange assigned\n";
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    // for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); ++it) {
    //     delete it->first;
    // }
}

int deleteSplit(std::string *tokens)
{
    delete [] tokens;
    return (1);
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
        int size;
        std::string *tokens = split(line, ',', size);
        if (!tokens)
            throw std::runtime_error("memory error");
        std::string date = tokens[0];
        double rate = std::strtod(tokens[1].c_str(), 0);
        deleteSplit(tokens);
        data[date] = rate;    
    }
    file.close();
}

std::string line_(std::string &l)
{
    if (l.empty())
        return "empty line";
    size_t i;
    for (i = 0; l[i] == ' '; i++)
        ;
    if (i == l.length())
        return "empty line";
    return l;
}
std::string rate_(std::string &l)
{
    if (l.empty())
        return "empty rate";
    size_t i;
    for (i = 0; l[i] == ' '; i++)
        ;
    if (i == l.length())
        return "empty rate";
    return l;
}

void BitcoinExchange::readInput(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (!file.is_open())
        throw std::runtime_error("could not open the file.");
    std::getline(file, line);
    int size;
    std::string *title = split(line, '|', size);
    if (!title || size != 2 || title[0] != "date" || title[1] != "value")
        deleteSplit(title), throw std::runtime_error("ivalid input format");
    deleteSplit(title);
    while (std::getline(file, line))
    {
        std::string *tokens = split(line, '|', size);
        if (size != 2 || !tokens)
            std::cout << "Error: bad input => " << line_(line);
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
                std::cout << "Erorr: bad rate => " << rate_(tokens[1]);
            else
                getBtc(date, rate);
        }
        deleteSplit(tokens);
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
    if (it != data.rend())
        return;
    std::cout << "Error: cannot find btc for this date";
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

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


std::string validDate(std::string &date)
{
    int size;
    std::string *tokens = split(date, '-', size);
    if (size != 3 || !tokens)
        return deleteSplit(tokens), "invalid date format";
    for (int i  = 0; i < 3; ++i)
    {
        if (checkToken(tokens[i]))
            return (deleteSplit(tokens), "ivalid date token");
    }
    if (tokens[1].length() > 2 || tokens[2].length() > 2)
        return deleteSplit(tokens), "ivalid date token";
    double year = strtod(tokens[0].c_str(), 0);
    double month = strtod(tokens[1].c_str(), 0);
    double day = strtod(tokens[2].c_str(), 0);
    deleteSplit(tokens);
    if (month > 12 || day > 31)
        return "date out of the valid range";
    const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int maxDays = days[(int)month];
    if (month == 2 && isLeapYear(year))
        maxDays = 29;
    if ( day > maxDays)
        return "date out of the valid range";
    return "";
}


bool isDouble(const std::string &s)
{
    if (s.empty())
        return false;
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

std::string* split(std::string s, char del, int &size)
{
    std::stringstream ss(s);
    std::string word;
    std::string *tokens = new std::string[3];

    size = 0;
    while (!ss.eof())
    {
        if (size >= 3 && deleteSplit(tokens))
            return  NULL;
        std::getline(ss, word, del);
        tokens[size] = trim(word);
        size++;
    }
    return tokens;
}

int compare_dates(const std::string &date1, const std::string &date2)
{
    int size;
    std::string *t1 = split(date1 , '-', size);
    std::string *t2 = split(date2 , '-', size);
    if (!t1 || !t2)
        throw std::runtime_error("memory Error\n");
    if (std::strtod(t1[0].c_str(), 0) < std::strtod(t2[0].c_str(), 0))
        return (deleteSplit(t1), deleteSplit(t2),-1);
    else if (std::strtod(t1[0].c_str(), 0) > std::strtod(t2[0].c_str(), 0))
        return (deleteSplit(t1), deleteSplit(t2),1);
    
    if (std::strtod(t1[1].c_str(), 0) < std::strtod(t2[1].c_str(), 0))
        return (deleteSplit(t1), deleteSplit(t2),-1);
    else if (std::strtod(t1[1].c_str(), 0) > std::strtod(t2[1].c_str(), 0))
        return (deleteSplit(t1), deleteSplit(t2),1);

    if (std::strtod(t1[2].c_str(), 0) < std::strtod(t2[2].c_str(), 0))
        return (deleteSplit(t1), deleteSplit(t2),-1);
    else if (std::strtod(t1[2].c_str(), 0) > std::strtod(t2[2].c_str(), 0))
        return (deleteSplit(t1), deleteSplit(t2),1);
    deleteSplit(t1), deleteSplit(t2);
    return (0);
}