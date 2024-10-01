/*=======================================================================================*/
/*===================== implementaion with vector =======================================*/
/*=======================================================================================*/

#include "PmergeMe.hpp"

void displayContainer(std::vector<std::pair<double, double> > vect)
{
    std::vector<std::pair<double, double> >::iterator it;

    for (it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << "[" <<   it->first << ", " << it->second << "]  ";
    }
    std::cout << std::endl;
}
void displayContainer(std::vector<double> vect)
{
    std::vector<double >::iterator it;

    for (it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void merge(const vector<pair<double,double> >& left, const vector<pair<double,double> >& right, vector<pair<double,double> >& result)
{
    vector<pair<double,double> >::const_iterator it_left = left.begin();
    vector<pair<double,double> >::const_iterator it_right = right.begin();

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

void insert(vector<double> &vect, double elem)
{
    if (elem < 0)
        return ;
    vector<double>::iterator pos = lower_bound(vect.begin(), vect.end(), elem);
    vect.insert(pos, elem);
}

void sortPair(vector<pair<double,double> > &data)
{
    if (data.size() < 2) return;

    vector<pair<double,double> > left, right;
    size_t mid = data.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid; i < data.size(); ++i) {
        right.push_back(data[i]);
    }

    sortPair(left);
    sortPair(right);
    vector<pair<double,double> > merged;
    merge(left, right, merged);
    data = merged;
}

void jacobSeq(vector<double> &vect, int size)
{
    for (int i =0; i < size; i++)
        vect.push_back(jacobVal(i));
}

void indexSeq(vector<double> & jacob,vector<double> & inds, int size)
{
    std::vector<double >::iterator it = jacob.begin();
    int tmp;
    int tmp2;

    it  += 2;
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

void insertSort(vector <double> &seq, vector <double> &res, int save)
{
    vector<double> jacob,inds;
    jacobSeq(jacob, 15);
    // displayContainer(jacob);
    indexSeq(jacob, inds, seq.size());
    for (vector <double>::iterator it = inds.begin(); it != inds.end(); ++it)
        {
            
            if (*(it) - 1 < (int)res.size())
            {
                insert(seq, res[*it - 1]);
            }
        }
        if (res.size()  &&  res[0])
            insert(seq, res[0]);
        if (save >= 0)
            insert(seq,save);
}

void splitSeq(std::vector<std::pair<double, double> > &vect, vector <double> &seq, vector <double> &res)
{
    for ( vector<pair<double, double> >::iterator it = vect.begin(); it != vect.end(); it++)
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


std::vector<std::pair<double, double> > parseNbs(char **nbs, int &size)
{
    std::vector<std::pair<double, double> > pairs;
    double first;
    double second;

    (1) && (nbs++, size--);
    while (size > 1)
    {
        if (!isInt(trim(*nbs)))
            throw std::runtime_error("invalid number");
        first = std::strtod(*nbs, 0); nbs++;
        second = std::strtod(*nbs, 0); nbs++;
        pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
        size -=2;
    }
    (size == 1) && (size = std::strtod(*nbs, 0));
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

void displayContainer(std::deque<std::pair<double, double> > vect)
{
    std::deque<std::pair<double, double> >::iterator it;

    for (it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << "[" <<   it->first << ", " << it->second << "]  ";
    }
    std::cout << std::endl;
}
void displayContainer(std::deque<double> vect)
{
    std::deque<double >::iterator it;

    for (it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void merge(const deque<pair<double,double> >& left, const deque<pair<double,double> >& right, deque<pair<double,double> >& result)
{
    deque<pair<double,double> >::const_iterator it_left = left.begin();
    deque<pair<double,double> >::const_iterator it_right = right.begin();

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

void insert(deque<double> &vect, double elem)
{
    if (elem < 0)
        return ;
    deque<double>::iterator pos = lower_bound(vect.begin(), vect.end(), elem);
    vect.insert(pos, elem);
}

void sortPair(deque<pair<double,double> > &data)
{
    if (data.size() < 2) return;

    deque<pair<double,double> > left, right;
    size_t mid = data.size() / 2;

    for (size_t i = 0; i < mid; ++i) {
        left.push_back(data[i]);
    }

    for (size_t i = mid; i < data.size(); ++i) {
        right.push_back(data[i]);
    }

    sortPair(left);
    sortPair(right);
    deque<pair<double,double> > merged;
    merge(left, right, merged);
    data = merged;
}

void jacobSeq(deque<double> &vect, int size)
{
    for (int i =0; i < size; i++)
        vect.push_back(jacobVal(i));
}

void indexSeq(deque<double> & jacob,deque<double> & inds, int size)
{
    std::deque<double >::iterator it = jacob.begin();
    int tmp;
    int tmp2;

    it  += 2;
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

void insertSort(deque <double> &seq, deque <double> &res, int save)
{
    deque<double> jacob,inds;
    jacobSeq(jacob, 15);
    // displayContainer(jacob);
    indexSeq(jacob, inds, seq.size());
    for (deque <double>::iterator it = inds.begin(); it != inds.end(); ++it)
        {
            
            if (*(it) - 1 < (int)res.size())
            {
                insert(seq, res[*it - 1]);
            }
        }
        if (res.size()  &&  res[0])
            insert(seq, res[0]);
        if (save >= 0)
            insert(seq,save);
}

void splitSeq(std::deque<std::pair<double, double> > &vect, deque <double> &seq, deque <double> &res)
{
    for ( deque<pair<double, double> >::iterator it = vect.begin(); it != vect.end(); it++)
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


std::deque<std::pair<double, double> > parseNbs_(char **nbs, int &size)
{
    std::deque<std::pair<double, double> > pairs;
    double first;
    double second;

    (1) && (nbs++, size--);
    while (size > 1)
    {
        if (!isInt(trim(*nbs)))
            throw std::runtime_error("invalid number");
        first = std::strtod(*nbs, 0); nbs++;
        second = std::strtod(*nbs, 0); nbs++;
        pairs.push_back(std::make_pair(std::max(first, second), std::min(first, second)));
        size -=2;
    }
    (size == 1) && (size = std::strtod(*nbs, 0));
    return pairs;
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