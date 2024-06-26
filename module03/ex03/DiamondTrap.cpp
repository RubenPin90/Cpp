/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/26 11:54:22 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), m_name(name) {
	this->m_attack = FragTrap::getInt("attack");
	this->m_hit = FragTrap::getInt("hit");
	this->m_energy = ScavTrap::getInt("energy");
	std::cout << GREEN "[DiamondTrap Default Constructor]:\t" RESET;
	std::cout << "DiamondTrap " << this->m_name << " was born." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref) {
	*this = ref;
	std::cout << BLUE "[DiamondTrap Copy Constructor]:\t" RESET;
	std::cout << "DiamondTrap " << this->m_name << " has been created." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	std::cout << BLUE "[DiamondTrap Assignement]:\t" RESET;
	std::cout << "DiamondTrap Assignement Operator called." << std::endl;
	this->m_name = rhs.m_name;
	this->m_hit = rhs.m_hit;
	this->m_attack = rhs.m_attack;
	this->m_energy = rhs.m_energy;
	this->m_failure = rhs.m_failure;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << RED "[DiamondTrap Deconstructor]:\t" RESET;
	std::cout << "DiamondTrap " << this->m_name << " has been destroyed." << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "Hi, I am a DiamondTrap named " << this->m_name << " originated from " << ClapTrap::m_name << std::endl;
}

std::string	DiamondTrap::getName(void) const {
	return this->m_name;
}

std::ostream& operator<<(std::ostream& ost, const DiamondTrap& rhs) {
	ost << rhs.getName();
	return (ost);
}
