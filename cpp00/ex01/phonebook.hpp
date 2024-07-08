/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:55:19 by mel-amar          #+#    #+#             */
/*   Updated: 2024/07/07 14:17:36 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
    private:
        std::string fname;
        std::string lname;
        std::string phone;
        std::string nickname;
        std::string secret;
        int index;
        int count;
    public:
        int get_index();
        int set_index(int index);
        int get_count();
        int set_count(int count);
        std::string get_fname();
        std::string set_fname(std::string fname);
        std::string get_lname();
        std::string set_lname(std::string lname);
        std::string get_nickname();
        std::string set_nickname(std::string lname);
        std::string get_phone();
        std::string set_phone(std::string phone);
        std::string get_secret();
        std::string set_secret(std::string secret);
};

class PhoneBook {
    public:
        Contact contact[8];
        void add_contact(Contact contact[8], Contact new_contact);
        void search_contact(Contact contact[8]);
};


Contact full_info();

#endif