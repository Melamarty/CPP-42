#pragma once

#include <iostream>

#include <vector>
#include <deque>
#include <iterator>
#include <utility>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::deque;
using std::stringstream;
using std::make_pair;
using std::min;
using std::max;
using std::cerr;
using std::exception;

//vector functions
std::vector<std::pair<double, double> > parseNbs(char **nbs, int &size);
std::string trim(const std::string &s);
void mergeInsert(std::vector<int> vect);
void displayContainer(std::vector<double> vect);
void sortPair(vector<pair<double,double> > &data);
void insertSort(vector <double> &seq, vector <double> &res, int save);
void splitSeq(std::vector<std::pair<double, double> > &vect, vector <double> &seq, vector <double> &res);

//deque functions
std::deque<std::pair<double, double> > parseNbs_(char **nbs, int &size);
std::string trim(const std::string &s);
void mergeInsert(std::deque<int> vect);
void displayContainer(std::deque<double> vect);
void displayContainer(std::deque<std::pair<double, double> > vect);
void sortPair(deque<pair<double,double> > &data);
void insertSort(deque <double> &seq, deque <double> &res, int save);
void splitSeq(std::deque<std::pair<double, double> > &vect, deque <double> &seq, deque <double> &res);


bool isInt(const std::string &s);
double jacobVal(int n);
char** duplicateArgs(int ac, char **av);
void freeArgs(int ac, char** av);