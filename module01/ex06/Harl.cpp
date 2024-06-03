/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 21:26:56 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void 		Harl::complain(std::string level) {
	std::string ar_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	PFnComplains funcPtr = {	&Harl::_debug, \
								&Harl::_info, \
								&Harl::_warning, \
								&Harl::_error };

	for(int i = 0; i < nLevels; i++) {
		if (ar_level[i] == level) {
			switch (i) {
				case 0:
					for(int i = 0; i < nLevels; i++) 
						(this->*funcPtr[i])();
					break;
				case 1:
					for(int i = 1; i < nLevels; i++) 
						(this->*funcPtr[i])();
					break;
				case 2:
					for(int i = 2; i < nLevels; i++) 
						(this->*funcPtr[i])();
					break;
				case 3:
					for(int i = 3; i < nLevels; i++) 
						(this->*funcPtr[i])();
					break;
				default:
					break;
			}
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]\n";
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
