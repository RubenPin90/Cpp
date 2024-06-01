/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:33 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/31 16:49:18 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << this->_name << " enters the salon and picks up the " << this->_weapon.getType() << ".\n";
}

HumanA::~HumanA(void) {
	std::cout << this->_name << " drops the " << this->_weapon.getType() << " and leaves the salon.\n";
}

void		HumanA::attack(void) const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}


