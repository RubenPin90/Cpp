/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:35:47 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/29 18:55:12 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}

void    PhoneBook::printlist(void) const{
    std::string frame = "---------------------------------------------\n";

    std::cout << frame;
    std::cout << "|" << std::setfill(' ') \
                    << std::setw(10) << "index" \
                    << "|" << std::setw(10) << "first name" \
                    << "|" << std::setw(10) << "last name" \
                    << "|" << std::setfill(' ') << std::setw(10) << "nickname" \
                    << "|" << std::endl;
    std::cout << frame;
    for (int i = 0; i < 8; i++) {
        std::cout << "|" << std::setfill(' ') \
                    << std::setw(10) << i \
                    << "|" << std::setw(10) << trunc(_people[i].getInfo("firstname")) \
                    << "|" << std::setw(10) << trunc(_people[i].getInfo("lastname")) \
                    << "|" << std::setw(10) << trunc(_people[i].getInfo("nickname")) \
                    << "|" << std::endl;
    }
    std::cout << frame;
}

void    PhoneBook::add(void) {
    static int   i;
    
    if (i == 8)
        i = 0;
    _people[i].setContact();
    if(std::cin) {
	    std::cout << "\nSUCCESS!\n";
	    std::cout << "New Person has been added to the contacts." << std::endl;
        i++;
    }
}

void    PhoneBook::search(void) const {
    std::string index;
    int         ret;
    std::string check;
    
    printlist();
    while (std::cin) {
        std::cout << "\nEnter the contact index you want to display: ";
        if (!std::getline(std::cin, index))
            break;
        if (index.length() == 1 && index[0] >= '0' && index[0] <= '7') {
            _people[index[0] - '0'].getContact();
            std::cout << "\nDo you want to see another contact? (Y / N)" << std::endl;
            if (!std::getline(std::cin, check))
			    break;
            ret = checkinput(check);
            if (ret < 0) {
                std::cerr << "\n***** Wrong input. Going back to HOME" << std::endl;
                break;
            } else if (ret == 0) {
                std::cout << "\n***** Going back to HOME" << std::endl;
                break;
            } else
               continue;
        }
        else
            std::cerr << "Wrong Input. Try again!" << std::endl;
    }
}

int    PhoneBook::ft_exit(void) const {
    int         ret;
    std::string check;

    ret = 0;
    while (std::cin) {
        std::cout << "Sure, you want to exit? All the contacts will be lost forever! (Y / N)" << std::endl;
        if (!std::getline(std::cin, check))
            break;
        ret = checkinput(check);
        if (ret < 0)
            std::cerr << "Wrong input. Try again.\n";
        else
            break;
    }
    return (ret);    
}
