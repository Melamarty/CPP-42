/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:55:10 by mel-amar          #+#    #+#             */
/*   Updated: 2024/07/07 15:50:00 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int Contact::get_index()
{
    return (this->index);
}
int Contact::set_index(int index)
{
    this->index = index;
    return (this->index);
}
int Contact::get_count()
{
    return (this->count);
}
int Contact::set_count(int count)
{
    this->count = count;
    return (this->count);
}
std::string Contact::get_fname()
{
    return (this->fname);
}
std::string Contact::set_fname(std::string fname)
{
    this->fname = fname;
    return (this->fname);
}
std::string Contact::get_nickname()
{
    return (this->nickname);
}
std::string Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
    return (this->nickname);
}
std::string Contact::get_lname()
{
    return (this->lname);
}
std::string Contact::set_lname(std::string lname)
{
    this->lname = lname;
    return (this->lname);
}
std::string Contact::get_phone()
{
    return (this->phone);
}
std::string Contact::set_phone(std::string phone)
{
    this->phone = phone;
    return (this->phone);
}
std::string Contact::get_secret()
{
    return (this->secret);
}
std::string Contact::set_secret(std::string secret)
{
    this->secret = secret;
    return (this->secret);
}

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
    std::string tmp;

    do {
        tmp = "";
        std::cout << "Enter first name >> ";
        std::getline (std::cin, tmp);
        if (std::cin.eof())
            exit (0);
    } while (tmp.empty());


    new_contact.set_fname(tmp);
    
    do {
        std::cout << "Enter last name >> ";
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit (0);
    } while (tmp.empty());

    new_contact.set_lname(tmp);

    do {
        std::cout << "Enter nick name >> ";
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit (0);
    } while (tmp.empty());
    new_contact.set_nickname(tmp);
    
    do {
        std::cout << "Enter phone number >> ";
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit (0);
    } while (tmp.empty() || !all_is_sigit(tmp));

    new_contact.set_phone(tmp);

    do {
        std::cout << "Enter secret >> ";
        std::getline(std::cin, tmp);
        if (std::cin.eof())
            exit (0);
    } while (tmp.empty());
    new_contact.set_secret(tmp);

    return new_contact;
}


void PhoneBook::add_contact(Contact contact[8], Contact new_contact)
{
    static int i;
    static int count;

   
    i = i % 8;
    count++;
    if (count >= 8)
        count = 8;
    contact[i] = new_contact;
    contact->set_count(count);
    contact->set_index(i);
    i++;
}

void    set_width(int len)
{
    while (len < 10)
    {
        std::cout << " ";
        len++;
    }
}

std::string setwd(std::string str)
{
    std::string tmp = str;
    if (tmp.length() >= 10)
        tmp = tmp.substr(0, 10);
        tmp[9] = '.';
    return (tmp);
}


void PhoneBook::search_contact(Contact contact[8])
{
    int i = 0;
    std::cout << "|";
    set_width(5);
    std::cout << "index" << "|";
    set_width(10);
    std::cout << "first name" << "|";
    set_width(9);
    std::cout << "last name" << "|";
    set_width(8);
    std::cout << "nickname" << "|";
    set_width(5);
    std::cout << "phone" << "|" << std::endl;
    while (i < contact->get_count())
    {
        std::cout << "|";
        std::cout <<  "         " << i << "|";
        set_width(contact[i].get_fname().length());
        std::cout << setwd(contact[i].get_fname()) << "|";
        
        set_width(contact[i].get_lname().length());
        std::cout << setwd(contact[i].get_lname()) << "|";
        
        set_width(contact[i].get_nickname().length());
        std::cout << setwd(contact[i].get_nickname()) << "|";
        
        set_width(contact[i].get_phone().length());
        std::cout << setwd(contact[i].get_phone()) << "|" << std::endl;
        i++;
    }
    std::cout << "enter index >> ";
    if (!(std::cin >> i))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         std::cout << "\033[31mInvalid index.\033[32m" << std::endl;
    }
    else if (i < 0 || i >= 8 || i >= contact->get_count()) 
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[31mInvalid index.\033[32m" << std::endl;
    }
    else
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "first name: " << contact[i].get_fname() << std::endl;
        std::cout << "last name: " << contact[i].get_lname() << std::endl;
        std::cout << "nick name: " << contact[i].get_nickname() << std::endl;
        std::cout << "phone number: " << contact[i].get_phone() << std::endl;
        std::cout << "secret: " << contact[i].get_secret() << std::endl;
    }
}


