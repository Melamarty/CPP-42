/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:55:10 by mel-amar          #+#    #+#             */
/*   Updated: 2024/01/13 04:55:11 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


int all_is_sigit(std::string str)
{
    int i = 0;

    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

Contact full_info()
{
    Contact new_contact;

    do {
        std::cout << "Enter first name >> ";
        std::getline(std::cin, new_contact.fname);
        if (std::cin.eof())
            exit (0);
    } while (new_contact.fname.empty());

    // Truncate or add a dot if the length is 10 characters
    new_contact.fname = new_contact.fname.substr(0, 10);
    if (new_contact.fname.length() == 10)
        new_contact.fname[9] = '.';

    do {
        std::cout << "Enter last name >> ";
        std::getline(std::cin, new_contact.lname);
        if (std::cin.eof())
            exit (0);
    } while (new_contact.lname.empty());
    new_contact.lname = new_contact.lname.substr(0, 10);
    if (new_contact.lname.length() == 10)
        new_contact.lname[9] = '.';

    do {
        std::cout << "Enter phone number >> ";
        std::getline(std::cin, new_contact.phone);
        if (std::cin.eof())
            exit (0);
    } while (new_contact.phone.empty() || !all_is_sigit(new_contact.phone));
    new_contact.phone = new_contact.phone.substr(0, 10);
    if (new_contact.phone.length() == 10)
        new_contact.phone[9] = '.';

    do {
        std::cout << "Enter secret >> ";
        std::getline(std::cin, new_contact.secret);
        if (std::cin.eof())
            exit (0);
    } while (new_contact.secret.empty());
    new_contact.secret = new_contact.secret.substr(0, 10);
    if (new_contact.secret.length() == 10)
        new_contact.secret[9] = '.';

    return new_contact;
}


void PhoneBook::add_contact(Contact contact[8], Contact new_contact)
{
    contact[contact->index] = new_contact;
    if (contact->count < 8)
        contact->count++;
    if (contact->index < 7)
        contact->index++;
    else
        contact->index = 0;
}

void PhoneBook::search_contact(Contact contact[8])
{
    int i = 0;
    std::cout << std::setw(10) << "index" << " | ";
    std::cout << std::setw(10) << "first name" << " | ";
    std::cout << std::setw(10) << "last name" << " | ";
    std::cout << std::setw(10) << "phone number" << " | " << std::endl;
    while (i < contact->count)
    {
        std::cout << std::setw(10) << i << " | ";
        std::cout << std::setw(10) << contact[i].fname << " | ";
        std::cout << std::setw(10) << contact[i].lname << " | ";
        std::cout << std::setw(10) << contact[i].phone << " | " << std::endl;
        i++;
    }
    std::cout << "enter index >> ";
    if (!(std::cin >> i)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
    } else if (i < 0 || i >= 8 || i >= contact->count) {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
    else
    {
        std::cout << "first name: " << contact[i].fname << std::endl;
        std::cout << "last name: " << contact[i].lname << std::endl;
        std::cout << "phone number: " << contact[i].phone << std::endl;
        std::cout << "secret: " << contact[i].secret << std::endl;
    }
}
