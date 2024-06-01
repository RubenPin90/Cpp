/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/31 16:55:59 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << this->_name << " enters the salon and has no weapon.\n";
}

HumanB::~HumanB(void) {
	std::cout << this->_name << " drops the " << this->_weapon->getType() << " and leaves the salon.\n";
}

void		HumanB::setWeapon(Weapon& newweapon) {
	this->_weapon = &newweapon;
}

void		HumanB::attack(void) const {
	if (this->_weapon) {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << this->_name << " has no weapon to attack with!" << std::endl;
    }
}