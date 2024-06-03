/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 20:44:39 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void print_welcome(void) {
    std::cout << "#######################" << std::endl;
    std::cout << "# WELCOME TO HARL 2.0 #" << std::endl;
    std::cout << "#######################" << std::endl;
    std::cout << std::endl;
}

void   ft_transform(std::string& str) {
    for(std::string::iterator it = str.begin(); it != str.end(); it++)
        *it = static_cast<char>(std::toupper(*it));
}

int main(void) {
	std::string input;
	Harl harl;

	print_welcome();
	while (std::cin) {
		std::cout << "Harl says: ";
		if (!std::getline(std::cin, input))
			break;
		ft_transform(input);
		if (input == "QUIT")
			return 0;
		harl.complain(input);
	}
		
		
}