#include "PmergeMe.hpp"


int main (int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "bad arguments\n";
        return 0;
    }
    {
        try
        {
            double save = -1;
            std::vector<double> vect = parseNbs(av, ac, save);
            displayContainer(vect, save);
            clock_t start = clock();
            sort(vect, save);
            clock_t end = clock();
            displayContainer(vect);
            displayTime(start, end, vect.size(), "vector");

        } catch (std::runtime_error &e)
        {
            std::cout << e.what() << std::endl;
            return (0);
        }
    }
    {
        try
        {
            double save = -1;
            std::deque<double> deq = parseNbs_(av, ac, save);
            displayContainer(deq, save);
            clock_t start = clock();
            sort(deq, save);
            clock_t end = clock();
            displayContainer(deq);
            displayTime(start, end, deq.size(), "deque");

        } catch (std::runtime_error &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}