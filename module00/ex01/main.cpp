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

int main () {
    std::string input;

    print_welcome();
    while (1) {
        std::cout << "Waiting for input: ";
        std::cin >> input;
        if (input == "ADD") {
            std::cout << "You entered: " << input << std::endl;
        }
        else if (input == "SEARCH") {
            std::cout << "You entered: " << input << std::endl;
        }
        else if (input == "EXIT") {
            std::cout << "You entered: " << input << std::endl;
            PhoneBook::exit();
        }
        else
            std::cout << "** Wrong input **" << std::endl << "Only ADD, SEARCH or EXIT accepted" << std::endl;
    }

}