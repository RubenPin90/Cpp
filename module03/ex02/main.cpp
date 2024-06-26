/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/23 12:04:23 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>

void attack(ScavTrap& aggressor, FragTrap& victim);
void print(const ScavTrap& obj1, const FragTrap& obj2);
std::ostream& operator<<(std::ostream& ost, const ClapTrap& rhs);

int main(void) {
	{
	ScavTrap scav("Scav");
	FragTrap frag("Frag");
	print(scav, frag);
	for(int i = 0; i < 2; i++) {
		attack(scav, frag);
	}
	scav.guardGate();
	frag.highFivesGuys();
	print(scav, frag);
	}
	return 0;
}

void attack(ScavTrap& aggressor, FragTrap& victim) {
	if (!victim.getBool())
		aggressor.attack(victim.getName());
	else 
		std::cout << RED "ATTACK FAILED!" RESET << std::endl;
	if (!aggressor.getBool())
		victim.takeDamage(aggressor.getInt("attack"));
}

void print(const ScavTrap& obj1, const FragTrap& obj2) {
	std::string frame = "-------------------------------------------------------------\n";
	std::string titles [] = {"Names", "Hit Points", "Energy Points", "Attack Damage"};
	std::cout << frame;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[0] \
				<< "|" << std::setw(19) << obj1 \
				<< "|" << std::setw(19) << obj2 
				<< "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[1] \
				<< "|" << std::setfill(' ') << std::setw(19) << obj1.getInt("hit") \
				<< "|" << std::setw(19) << obj2.getInt("hit") 
				<< "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[2] \
				<< "|" << std::setfill(' ') << std::setw(19) << obj1.getInt("energy") \
				<< "|" << std::setw(19) << obj2.getInt("energy") 
				<< "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[3] \
				<< "|" << std::setfill(' ') << std::setw(19) << obj1.getInt("attack") \
				<< "|" << std::setw(19) << obj2.getInt("attack") 
				<< "|" << std::endl;
	std::cout << frame;
}

std::ostream& operator<<(std::ostream& ost, const ClapTrap& rhs) {
	ost << rhs.getName();
	return (ost);
}
