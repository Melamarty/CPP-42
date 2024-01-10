#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
    public:
        std::string fname;
        std::string lname;
        std::string phone;
        std::string secret;
        int index;
        int count;
};

class PhoneBook {
    public:
        Contact contact[8];
        void add_contact(Contact contact[8], Contact new_contact);
        void search_contact(Contact contact[8]);
};

Contact full_info();

#endif