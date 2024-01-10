#include "phonebook.hpp"

int main ()
{
    PhoneBook phonebook;

    std::cout << "\033[32m <<<<< welcome to the megaphone >>>>> " << std::endl;
    phonebook.contact->index = 0;
    phonebook.contact->count = 0;
    while (1)
    {
        Contact new_contact;
        std::string tmp;
        do
        {
            std::cout << "\033[33enter a cmd >> ";
            std::getline(std::cin, tmp);
            if (std::cin.eof())
                exit (0);
        } while (tmp.empty());
        if (tmp == "ADD")
        {
            new_contact = full_info();
            phonebook.add_contact(phonebook.contact, new_contact);
        }
        else if (tmp == "SEARCH")
            phonebook.search_contact(phonebook.contact);
        else if (tmp == "EXIT")
            exit (0);
        else
            std::cout << "\033[31merror: invalid cmd\033[32m" << std::endl;
    }
}