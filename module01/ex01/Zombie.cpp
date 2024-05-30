/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:23:10 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 21:59:21 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	static int i;
	std::cout << "Zombie " << ++i << " was created!\n";
	_id = i;
} 

Zombie::~Zombie(void) {
	std::cout << _name << " " << _id << " zombie died.\n";
}

void	Zombie::setname(std::string str) {
	std::cout << "Zombie " << _id << " is named " << str << "." << std::endl;
	_name = str;
}

void	Zombie::announce(void) {
	std::cout << _name << " " << _id << ":" << RED << " BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}