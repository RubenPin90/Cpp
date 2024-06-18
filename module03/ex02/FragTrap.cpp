/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/18 21:23:42 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->m_attack = FRAG_DMG_PNT;
	this->m_energy = FRAG_NRG_MAX;
	this->m_hit = FRAG_HIT_MAX;
	this->m_failure = false;
	std::cout << GREEN"[FragTrap Default Constructor]:\t"RESET;
	std::cout << "FragTrap " << this->m_name << " was born." << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref) {
	std::cout << BLUE"[FragTrap Copy Constructor]:\t"RESET;
	std::cout << "FragTrap " << this->m_name << " has been created." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << RED"[FragTrap Deconstructor]:\t"RESET;
	std::cout << "FragTrap " << this->m_name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->m_name << " is requesting high fives!" << std::endl;
}

