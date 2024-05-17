/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:35:47 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/17 16:14:39 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}

std::string PhoneBook::trunc(std::string str) {
    std::string newstr;
    
    if (str.size > 10) {
        newstr = str.resize(9) + ".";
    }
    else
        newstr = str;
    return (newstr);
}


void    PhoneBook::printlist(void) const {
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
                    << "|" << std::setw(10) << PhoneBook::trunc(_people, i) \
                    << "|" << std::setw(10) << PhoneBook::trunc(_people, i) \
                    << "|" << std::setfill(' ') << std::setw(10) << "test" \
                    << "|" << std::endl;
    }
    std::cout << frame;
}


int    PhoneBook::ft_exit(void) const {
    char check;

    while (1) {
        std::cout << "Sure, you want to exit? All the contacts will be lost forever! (Y / N)" << std::endl;
        std::cin >> check;
        if (check == 'N' || check == 'n')
            return (0);
        else if (check == 'Y' || check == 'y')
            return (1);
    }           
}