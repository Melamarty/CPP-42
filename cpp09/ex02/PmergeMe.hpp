#pragma once

#include <iostream>

#include <vector>
#include <deque>
#include <iterator>
#include <utility>
#include <ctime>

//vector functions
void sort(std::vector<double> &vect, double save);
std::vector<double> parseNbs(char **nbs, int size, double &save);
std::vector<std::pair<double, double> > makePairs(std::vector<double> vect);
std::string trim(const std::string &s);
void mergeInsert(std::vector<int> vect);
void displayContainer(std::vector<double> vect);
void displayContainer(std::vector<double> vect, double save);
void sortPair(std::vector<std::pair<double,double> > &data);
void insertSort(std::vector <double> &seq, std::vector <double> &res, double save);
void splitSeq(std::vector<std::pair<double, double> > &vect, std::vector <double> &seq, std::vector <double> &res);

//deque functions
void sort(std::deque<double> &vect, double save);
std::deque<double> parseNbs_(char **nbs, int size, double &save);
std::deque<std::pair<double, double> > makePairs_(std::deque<double> vect);
std::string trim(const std::string &s);
void mergeInsert(std::deque<int> vect);
void displayContainer(std::deque<double> vect);
void displayContainer(std::deque<double> vect, double save);
void sortPair(std::deque<std::pair<double,double> > &data);
void insertSort(std::deque <double> &seq, std::deque <double> &res, double save);
void splitSeq(std::deque<std::pair<double, double> > &vect, std::deque <double> &seq, std::deque <double> &res);


bool isInt(const std::string &s);
double jacobVal(int n);
void displayTime(clock_t start, clock_t end, int size, const std::string &type);