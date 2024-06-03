/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 20:41:39 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void 		Harl::complain(std::string level) {
	bool check = false;
	std::string ar_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	PFnComplains funcPtr = {	&Harl::_debug, \
								&Harl::_info, \
								&Harl::_warning, \
								&Harl::_error };
	
	for(int i = 0; i < nLevels; i++) {
		if (ar_level[i] == level) {
			(this->*funcPtr[i])();
			check = true;
			break;
		}
	}
	if (check == false) {
			std::cerr << "Ups. This complain is not registered.\n";
			std::cout << "Accepted complains: <DEBUG>, <INFO>, <WARNING>, <ERROR>\n";
			std::cout << "\t\t    Enter <quit> to leave Harl alone.\n";
		}
}

void Harl::_debug(void) {
	std::cout << GREEN << "[ DEBUG ] // " << RESET;
	std::cout << MSG_DEBUG << std::endl;
}

void Harl::_info(void) {
	std::cout << YELLOW << "[ INFO ] // " << RESET;
	std::cout << MSG_INFO << std::endl;
}

void Harl::_warning(void) {
	std::cout << BLUE << "[ WARNING ] // " << RESET;
	std::cout << MSG_WARNING << std::endl;
}

void Harl::_error(void) {
	std::cout << RED << "[ ERROR ] // " << RESET;
	std::cout << MSG_ERROR << std::endl;
}
