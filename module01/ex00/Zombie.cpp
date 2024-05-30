/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:37:26 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 21:42:02 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie " << GREEN << this->_name << RESET << " is born.\n";
	this->announce();
}

Zombie::~Zombie(void) {
	std::cout << RED << this->_name << " Zombie died!\n" << RESET;
}

void	Zombie::announce(void) {
	std::cout << GREEN << this->_name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}