/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:14:21 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/02 16:23:38by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

void print_welcome() {
    std::cout << "################################" << std::endl;
    std::cout << "# WELCOME TO RUBEN'S PHONEBOOK #" << std::endl;
    std::cout << "################################" << std::endl;
    std::cout << std::endl;
}

int checkinput(std::string str) {
    char check;

    if (str.length() == 1) {
        check = std::tolower(str[0]);
        return ((check == 'n') ? 0 : ((check == 'y') ? 1 : -1));
    }
    return (-1);
}

std::string trunc(std::string str) {
    if (str.size() > 10) {
        str.resize(9);
        str += '.';
    }
    return (str);
}

int main () {
    std::string input;
    PhoneBook   rubenbook;

    print_welcome();
    while (std::cin) {
        std::cout << "\n" << "Waiting for input: ";
        std::cin >> input;
        if (!std::cin)
            break;
        if (input == "ADD") {
            rubenbook.add();
        }
        else if (input == "SEARCH") {
            rubenbook.search();
        }
        else if (input == "EXIT") {
            if (rubenbook.ft_exit())
                break;
        }
        else {
            std::cout << "** Wrong input **" << std::endl;
            std::cout << "Only ADD, SEARCH or EXIT accepted" << std::endl;
        }
    }
    return (0);
}