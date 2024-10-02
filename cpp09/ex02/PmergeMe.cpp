/*=======================================================================================*/
/*===================== implementaion with vector =======================================*/
/*=======================================================================================*/

#include "PmergeMe.hpp"


void sort(std::vector<double> &vect, double save)
{
    std::vector<std::pair<double, double> > pairs = makePairs(vect);
    sortPair(pairs);
    std::vector <double> seq , res;
    splitSeq(pairs, seq, res);
    insertSort(seq, res, save);
    vect = seq;
}

void displayContainer(std::vector<double> vect, double save)
{
    std::cout << "\033[32m" << "===============  vector  ====================\n" << "\033[37m";
    std::cout << "Before: ";
    std::vector<double>::iterator it;

    int i = 0;
    for (it = vect.begin(); it != vect.end() && ++i < 5; ++it)
    {
        std::cout << *it << " ";
    }
    if (save >= 0)
        std::cout << save;
    if (i >= 5 && it != vect.end())
        std::cout << "[...]";
    std::cout << std::endl;
}

void displayContainer(std::vector<double> vect)
{
    std::vector<double >::iterator it;

    std::cout << "After: ";
    int i = 0;
    for (it = vect.begin(); it != vect.end() && ++i <= 5; ++it)
    {
        std::cout << *it << " ";
    }
    if (i >= 5 && it != vect.end())
        std::cout << "[...]";
    std::cout << std::endl;
}

void merge(const std::vector<std::pair<double,double> >& left, const std::vector<std::pair<double,double> >& right, std::vector<std::pair<double,double> >& result)
{
    std::vector<std::pair<double,double> >::const_iterator it_left = left.begin();
    std::vector<std::pair<double,double> >::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (it_left->first <= it_right->first) {
            result.push_back(*it_left);
            ++it_left;
        } else {
            result.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end()) {
        result.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) {
        result.push_back(*it_right);
        ++it_right;
    }
}

void insert(std::vector<double> &vect, double elem)
{
    if (elem < 0)
        return ;
    std::vector<double>::iterator pos = lower_bound(vect.begin(), vect.end(), elem);
    vect.insert(pos, elem);
}

void sortPair(std::vector<std::pair<double,double> > &data)
{
    if (data.size() < 2) return;

    std::vector<std::pair<double,double> > left, right;
    size_t mid = data.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid; i < data.size(); ++i) {
        right.push_back(data[i]);
    }

    sortPair(left);
    sortPair(right);
    std::vector<std::pair<double,double> > merged;
    merge(left, right, merged);
    data = merged;
}

void jacobSeq(std::vector<double> &vect, int size)
{
    for (int i =0; i < size; i++)
        vect.push_back(jacobVal(i));
}

void indexSeq(std::vector<double> & jacob,std::vector<double> & inds, int size)
{
    std::vector<double >::iterator it = jacob.begin();
    int tmp;
    int tmp2;

    it  += 1; //
    int i = 0;
    while (it != jacob.end())
    {
        tmp = *it;
        it++;
        if (it == jacob.end())
            return ;
        tmp2 = *it;
        inds.push_back(tmp2);
        while (--tmp2 > tmp)
            inds.push_back(tmp2);
        ++i;
        if (i > size)
            return ;
    }
}

void insertSort(std::vector <double> &seq, std::vector <double> &res, double save)
{
    std::vector<double> jacob,inds;
    jacobSeq(jacob, 15);
    indexSeq(jacob, inds, seq.size() / 2);
    for (std::vector <double>::iterator it = inds.begin(); it != inds.end(); ++it)
    {
        if (*(it) < (int)res.size()) //
            insert(seq, res[*it]); //
    }
    if (res.size())
        insert(seq, res[0]);
    if (save >= 0)
        insert(seq,save);
}

void splitSeq(std::vector<std::pair<double, double> > &vect, std::vector <double> &seq, std::vector <double> &res)
{
    for ( std::vector<std::pair<double, double> >::iterator it = vect.begin(); it != vect.end(); it++)
    {
        seq.push_back(it->first);
        res.push_back(it->second);
    }
    if (res.size() > 0)
    {
        insert(seq, *res.begin());
        res.erase(res.begin());
    }
}


std::vector<double> parseNbs(char **nbs, int size, double &save)
{
    std::vector<double> vect;
    double first;
    double second;

    (1) && (nbs++, size--);
    while (size > 1)
    {
        if (!isInt(trim(*nbs)) || !isInt(trim(*(nbs + 1))))
            throw std::runtime_error("\033[31mError:\033[37m invalid number");
        first = std::strtod(*nbs, 0); nbs++;
        second = std::strtod(*nbs, 0); nbs++;
        if (first < 0 || second < 0)
            throw::std::runtime_error("\033[31mError:\033[37m a negative number found");
        vect.push_back(first);
        vect.push_back(second);
        size -=2;
    }
    if (size > 0 && !isInt(trim(*nbs)))
        throw std::runtime_error("\033[31mError:\033[37m invalid number");
    if (size == 1 && std::strtod(*nbs, 0) < 0)
        throw::std::runtime_error("\033[31mError:\033[37m a negative number found");
    (size == 1) && (save = std::strtod(*nbs, 0));
    return vect;
}

std::vector<std::pair<double, double> > makePairs(std::vector<double> vect)
{
    std::vector<std::pair<double, double> > pairs;
    std::vector<double>::iterator it;

    for (it = vect.begin(); it != vect.end(); it += 2)
        pairs.push_back(std::make_pair(std::max(*it, *(it + 1)), std::min(*it, *(it + 1))));
    return pairs;
}

void mergeInsert(std::vector<int> vect)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int>::iterator it;
    for (it = vect.begin(); it != vect.end(); it++)
    {
        double tmp = *it;
        ++it;
        if (*it < tmp)
            pairs.push_back(std::make_pair(tmp, *it));
        else
            pairs.push_back(std::make_pair(*it, tmp));
    }
}

bool isInt(const std::string &s)
{
    char *end = NULL;

    if (s.empty())
        return false;
    std::strtol(s.c_str(), &end, 10);
    std::string res = end;
    return (res.empty());
}

double jacobVal(int n)
{
    return ((pow(2, n) - pow(-1, n))/ 3);
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










/*=======================================================================================*/
/*===================== implementaion with deque ========================================*/
/*=======================================================================================*/










void displayContainer(std::deque<double> vect, double save)
{
    std::cout << "\033[32m" <<  "===============  deque  ====================\n" << "\033[37m";
    std::cout << "Before: ";
    std::deque<double>::iterator it;

    int i = 0;
    for (it = vect.begin(); it != vect.end() && ++i < 5; ++it)
    {
        std::cout << *it << " ";
    }
    if (save >= 0 && ++i)
        std::cout << save;
    if (i >= 5 && it != vect.end())
        std::cout << "[...]";
    std::cout << std::endl;
}
void displayContainer(std::deque<double> vect)
{
    std::deque<double >::iterator it;

    std::cout << "After: ";
    int i = 0;
    for (it = vect.begin(); it != vect.end() && ++i <= 5; ++it)
    {
        std::cout << *it << " ";
    }
    if (i >= 5 && it != vect.end())
        std::cout << "[...]";
    std::cout << std::endl;
}

void merge(const std::deque<std::pair<double,double> >& left, const std::deque<std::pair<double,double> >& right, std::deque<std::pair<double,double> >& result)
{
    std::deque<std::pair<double,double> >::const_iterator it_left = left.begin();
    std::deque<std::pair<double,double> >::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (it_left->first <= it_right->first) {
            result.push_back(*it_left);
            ++it_left;
        } else {
            result.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end()) {
        result.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) {
        result.push_back(*it_right);
        ++it_right;
    }
}

void insert(std::deque<double> &vect, double elem)
{
    if (elem < 0)
        return ;
    std::deque<double>::iterator pos = lower_bound(vect.begin(), vect.end(), elem);
    vect.insert(pos, elem);
}

void sortPair(std::deque<std::pair<double,double> > &data)
{
    if (data.size() < 2) return;

    std::deque<std::pair<double,double> > left, right;
    size_t mid = data.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid; i < data.size(); ++i) {
        right.push_back(data[i]);
    }

    sortPair(left);
    sortPair(right);
    std::deque<std::pair<double,double> > merged;
    merge(left, right, merged);
    data = merged;
}

void jacobSeq(std::deque<double> &vect, int size)
{
    for (int i =0; i < size; i++)
        vect.push_back(jacobVal(i));
}

void indexSeq(std::deque<double> & jacob,std::deque<double> & inds, int size)
{
    std::deque<double >::iterator it = jacob.begin();
    int tmp;
    int tmp2;

    it  += 1;
    int i = 0;
    while (it != jacob.end())
    {
        tmp = *it;
        it++;
        if (it == jacob.end())
            return ;
        tmp2 = *it;
        inds.push_back(tmp2);
        while (--tmp2 > tmp)
            inds.push_back(tmp2);
        ++i;
        if (i > size)
            return ;
    }
}

void insertSort(std::deque <double> &seq, std::deque <double> &res, double save)
{
    std::deque<double> jacob,inds;
    jacobSeq(jacob, 15);
    // displayContainer(jacob);
    indexSeq(jacob, inds, seq.size() / 2);
    for (std::deque <double>::iterator it = inds.begin(); it != inds.end(); ++it)
    {
        
        if (*(it) < (int)res.size())
        {
            insert(seq, res[*it]);
        }
    }
    if (res.size())
        insert(seq, res[0]);
    if (save >= 0)
        insert(seq,save);
}

void splitSeq(std::deque<std::pair<double, double> > &vect, std::deque <double> &seq, std::deque <double> &res)
{
    for ( std::deque<std::pair<double, double> >::iterator it = vect.begin(); it != vect.end(); it++)
    {
        seq.push_back(it->first);
        res.push_back(it->second);
    }
    if (res.size() > 0)
    {
        insert(seq, *res.begin());
        res.erase(res.begin());
    }
}

void mergeInsert(std::deque<int> vect)
{
    std::deque<std::pair<int, int> > pairs;
    std::deque<int>::iterator it;
    for (it = vect.begin(); it != vect.end(); it++)
    {
        double tmp = *it;
        ++it;
        if (*it < tmp)
            pairs.push_back(std::make_pair(tmp, *it));
        else
            pairs.push_back(std::make_pair(*it, tmp));
    }
}


std::deque<double> parseNbs_(char **nbs, int size, double &save)
{
    std::deque<double> vect;
    double first;
    double second;

    (1) && (nbs++, size--);
    while (size > 1)
    {
        if (!isInt(trim(*nbs)) || !isInt(trim(*(nbs + 1))))
            throw std::runtime_error("\033[31mError:\033[37m invalid number");
        first = std::strtod(*nbs, 0); nbs++;
        second = std::strtod(*nbs, 0); nbs++;
        if (first < 0 || second < 0)
            throw::std::runtime_error("\033[31mError:\033[37m negative number found");
        vect.push_back(first);
        vect.push_back(second);
        size -=2;
    }
    if (size > 0 && !isInt(trim(*nbs)))
        throw std::runtime_error("\033[31mError:\033[37m minvalid number");
    if (size == 1 && std::strtod(*nbs, 0) < 0)
        throw::std::runtime_error("\033[31mError:\033[37m a negative number found");
    (size == 1) && (save = std::strtod(*nbs, 0));
    return vect;
}

std::deque<std::pair<double, double> > makePairs_(std::deque<double> vect)
{
    std::deque<std::pair<double, double> > pairs;
    std::deque<double>::iterator it;

    for (it = vect.begin(); it != vect.end(); it += 2)
        pairs.push_back(std::make_pair(std::max(*it, *(it + 1)), std::min(*it, *(it + 1))));
    return pairs;
}


void sort(std::deque<double> &deq, double save)
{
    std::deque<std::pair<double, double> > pairs = makePairs_(deq);
    sortPair(pairs);
    std::deque <double> seq , res ;
    splitSeq(pairs, seq, res);
    insertSort(seq, res, save);
    deq = seq;
}


void displayTime(clock_t start, clock_t end, int size, const std::string &type)
{

    double time = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "time to sort a range of " << size << " with " << type << ": \033[34m" << time << " us\033[37m" << std::endl; 
}