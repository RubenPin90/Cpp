/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:35:47 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/03 14:07:34 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}

int    PhoneBook::exit(void) {
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