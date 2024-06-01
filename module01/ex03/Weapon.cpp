/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:23:10 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/31 16:40:22 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "A weapon of type " << this->_type << " appears on the table.\n";
}

Weapon::~Weapon(void) {
	std::cout << this->_type << " was destroyed.\n";
}

void	Weapon::setType(std::string newtype) {
	_type = newtype;
}

std::string	Weapon::getType(void) const {
	return(_type);
}