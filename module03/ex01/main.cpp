/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/18 21:00:26 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

void attack(ClapTrap& aggressor, ClapTrap& victim);
void print(const ClapTrap& obj1, const ClapTrap& obj2);

int main(void) {
	{ 
	ClapTrap bob("Bob");
	ClapTrap clone(bob);
	print(bob, clone);
	for(int i = 0; i < 11; i++)
		attack(bob, clone);
	clone.beRepaired(1);
	print(bob, clone);
	}
	std::cout << "\n=========================================\n" << std::endl;
	{
	ClapTrap clap("Clap");
	ScavTrap scav("Scav");
	print(scav, clap);
	for(int i = 0; i < 5; i++) {
		attack(scav, clap);
	}
	scav.guardGate();
	print(scav, clap);
	}
	
	return 0;
}

void attack(ClapTrap& aggressor, ClapTrap& victim) {
	if (!victim.getBool())
		aggressor.attack(victim.getName());
	else 
		std::cout << RED"ATTACK FAILED!"RESET << std::endl;
	if (!aggressor.getBool())
		victim.takeDamage(aggressor.getInt("attack"));
}

void print(const ClapTrap& obj1, const ClapTrap& obj2) {
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
