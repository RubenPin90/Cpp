/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/18 21:05:33 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	m_initvalues();
	std::cout << GREEN"[ScavTrap Default Constructor]:\t"RESET;
	std::cout << "ScavTrap " << this->m_name << " was born." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref) {
	std::cout << BLUE"[ScravTrap Copy Constructor]:\t"RESET;
	std::cout << "ScravTrap " << this->m_name << " has been created." << std::endl;
}


ScavTrap::~ScavTrap(void) {
	std::cout << RED"[ScravTrap Deconstructor]:\t"RESET;
	std::cout << "ScravTrap " << this->m_name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << YELLOW"[New Action//Attack]\t"RESET;
	if (this->m_energy && this->m_hit) {
		std::cout << "ScavTrap "<< this->m_name << " attacks " << target \
			<< ", causing " << this->m_attack << " points of damage!" << std::endl;
		this->m_energy--;
	} else {
		std::cout << "ScavTrap " << this->m_name << " has not enough energy to attack." << std::endl;
		this->m_failure = true;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << YELLOW"[Action//GuardGate]\t"RESET;
	if (this->m_guard == false) {
		this->m_guard = true;
		std::cout << "ScravTrap " << this->m_name << " is now in Gatekeeper mode!" << std::endl;
	} else {
		std::cout << "ScravTrap " << this->m_name << " is already in Gatekeeper mode" << std::endl;
	}
}

void ScavTrap::m_initvalues(void) {
	this->m_attack = SCAV_DMG_PNT;
	this->m_energy = SCAV_NRG_MAX;
	this->m_hit = SCAV_HIT_MAX;
	this->m_guard = false;
	this->m_failure = false;
}

