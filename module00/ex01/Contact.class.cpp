/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:35:51 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/22 16:42:26 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
    return;
}

Contact::~Contact(void) {
    return;
}

void    Contact::setContact(void) {
   std::cout << "<Adding new contact>\n";
   std::cout << "What is the first name?\n";
   std::cin >> _firstn;
   std::cout << "What is" << _firstn << "'s last name?\n";
   std::cin >> _lastn;
   std::cout << "Does" << _firstn << " " << _lastn << " have a nickname?\n";
   std::cin >> _nickn;
   std::cout << "What is" << _nickn << "'s phone number?\n";
   std::cin >> _phone;
   std::cout << "What is" << _nickn << "'s darkest secret?\n";
   std::cin >> _secret;
   std::cout << "\nSUCCESS!\n";
   std::cout << _firstn << " " << _lastn << " alias " << _nickn << " has been added to the contacts." << std::endl;
}

void    Contact::getContact(void) const {
    std::cout << "First name: " << _firstn << "\n";
    std::cout << "Last name: " << _lastn << "\n";
    std::cout << "Nickname: " << _nickn << "\n";
    std::cout << "Phone Number: " << _phone << "\n";
    std::cout << "Darkest Secret: " << _secret << std::endl;
}

std::string    Contact::getInfo(std::string str) const {
    if (str == "firstname")
        return (_firstn);
    else if (str == "lastname")
        return (_lastn);
    else if (str == "nickname")
        return (_nickn);
    else if (str == "phone")
        return (_phone);
    else if (str == "secret")
        return (_secret);
    else
        return (NULL);
}

