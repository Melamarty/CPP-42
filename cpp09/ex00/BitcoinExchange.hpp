#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map <std::string, double> data;
        std::map <std::string, double> input;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &bt);
        BitcoinExchange &operator=(const BitcoinExchange &bt);
        ~BitcoinExchange();
        void readData(std::string );
        void readInput(std::string);
        void displayData();
        void displayInput();
        void getBtc(std::string &date, double &rate);
};

int isDigit(const std::string &s);
bool checkToken(std::string token);
std::string validDate(std::string &date);
bool isDouble(const std::string &s);
std::string trim(const std::string &s);
std::vector<std::string> split(std::string s, char del);
int compare_dates(const std::string &date1, const std::string &date2);