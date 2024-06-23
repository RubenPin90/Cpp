/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/23 12:01:05 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#define HITPOINTS_MAX 10
#define EPOINTS_MAX 10
#define DAMAGE_POINTS 0

ClapTrap::ClapTrap(const std::string& name) : m_name(name), m_hit(HITPOINTS_MAX), \
				m_energy(EPOINTS_MAX), m_attack(DAMAGE_POINTS), m_failure(false) {
	std::cout << GREEN "[ClapTrap Default Constructor]:\t" RESET;
	std::cout << "ClapTrap " << this->m_name << " was born." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) : m_name(ref.m_name + "'s clone"), m_hit(ref.m_hit), m_energy(ref.m_energy), m_attack(ref.m_attack) {
	std::cout << BLUE "[ClapTrap Copy Constructor]:\t" RESET;
	std::cout << "ClapTrap " << this->m_name << " has been created." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << RED "[ClapTrap Deconstructor]:\t" RESET;
	std::cout << "ClapTrap " << this->m_name << " has been destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	this->m_name = rhs.m_name;
	this->m_hit = rhs.m_hit;
	this->m_attack = rhs.m_attack;
	this->m_energy = rhs.m_energy;
	this->m_failure = rhs.m_failure;
	return *this;
}

//Getter
std::string	ClapTrap::getName(void) const {
	return this->m_name;
}

int	ClapTrap::getInt(const std::string& value) const {
	std::string values[] = {"hit", "energy", "attack"};
	int array_size = sizeof(values) / sizeof(values[0]);
	int tmp = -1;

	for (int i = 0; i < array_size; i++) {
		if (values[i] == value) {
			switch (i) {
				case 0:
					tmp = this->m_hit;
					break;
				case 1:
					tmp = this->m_energy;
					break;
				case 2:
					tmp = this->m_attack;
					break;
				default:
					break;
			}
		}
	}
	return tmp;
}

bool	ClapTrap::getBool(void) const {
	return this->m_failure;
}

//Methods
void ClapTrap::attack(const std::string& target) {
	std::cout << YELLOW "[Action//Attack]\t" RESET;
	if (this->m_energy && this->m_hit) {
		std::cout << "ClapTrap "<< this->m_name << " attacks " << target \
			<< ", causing " << this->m_attack << " points of damage!" << std::endl;
		this->m_energy--;
	} else {
		std::cout << "ClapTrap " << this->m_name << " has not enough energy to attack." << std::endl;
		this->m_failure = true;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << YELLOW "[Action//takeDamage]\t" RESET;
	if (this->m_hit > 0) {
		this->m_hit -= amount;
		std::cout << "Ouch! " << "ClapTrap " << this->m_name << " took " << amount << " hit points damage!" << std::endl;
		if (m_hit <= 0)
			this->m_failure = true;
	} else {
		std::cout << "ClapTrap " << this->m_name << " has no hit points left." << std::endl;
		this->m_failure = true;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << YELLOW "[Action//Repair]\t" RESET;
	if (this->m_energy <= 0) {
		std::cout << "ClapTrap " << this->m_name << " has not enough energy left to heal." << std::endl;
		this->m_failure = true;
	}		
	else if ((this->m_hit + amount) > HITPOINTS_MAX) 
		std::cout << "ClapTrap " << this->m_name << " can't heal over his max hit points." << std::endl;
	else {
		this->m_hit += amount; 
		this->m_energy--;
		std::cout << "ClapTrap " << this->m_name << " healed " << amount << " hit points." << std::endl;
	}
}


