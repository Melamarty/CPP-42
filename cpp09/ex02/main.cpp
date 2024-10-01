#include "PmergeMe.hpp"


int main (int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "bad arguments\n";
        return 0;
    }
    int tmp = ac;
    std::cout << "\033[32m" << "===============  vector  ====================\n" << "\033[37m";
    /*========== vector =========*/
    {
        try
        {
            int t = !(ac % 2);
            (void)t;
            std::vector<std::pair<double, double> > vect = parseNbs(av, ac);
            sortPair(vect);
            vector <double> seq , res ;
            splitSeq(vect, seq, res);
            if (!t)
                ac = -1;
            insertSort(seq, res, ac);
            displayContainer(seq);

        } catch (std::runtime_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\033[32m" <<  "===============  deque  ====================\n" << "\033[37m";
    {
        try
        {
            int t = !(tmp % 2);
            (void)t;
            std::deque<std::pair<double, double> > vect = parseNbs_(av, tmp);
            sortPair(vect);
            deque <double> seq , res ;
            splitSeq(vect, seq, res);
            if (!t)
                ac = -1;
            insertSort(seq, res, ac);
            displayContainer(seq);

        } catch (std::runtime_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    /*========== deque =========*/
}

char** duplicateArgs(int ac, char **av)
{
    char** newAv = new char*[ac];

    for (int i = 0; i < ac; ++i) {
        newAv[i] = new char[strlen(av[i]) + 1];
        std::strcpy(newAv[i], av[i]);
    }

    return newAv;
}

void freeArgs(int ac, char** av)
{
    for (int i = 0; i < ac; ++i) {
        delete[] av[i];
    }
    delete[] av;
}