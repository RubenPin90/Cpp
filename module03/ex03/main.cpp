/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/23 19:02:34 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iomanip>

void attack(DiamondTrap& aggressor, DiamondTrap& victim);
void print(const DiamondTrap& obj1, const DiamondTrap& obj2);

int main(void) {
	{
	DiamondTrap a("Dia");
	DiamondTrap a_clone(a);
	DiamondTrap b("Mond");

	a.whoAmI();
	b.whoAmI();
	a_clone.whoAmI();
	a_clone = b;
	a_clone.whoAmI();
	
	print(a, b);
	attack(a, b);
	b.beRepaired(10);
	print(a, b);
	}
	return 0;
}

void attack(DiamondTrap& aggressor, DiamondTrap& victim) {
	if (!victim.getBool())
		aggressor.attack(victim.getName());
	else 
		std::cout << RED "ATTACK FAILED!" RESET << std::endl;
	if (!aggressor.getBool())
		victim.takeDamage(aggressor.getInt("attack"));
}

void print(const DiamondTrap& obj1, const DiamondTrap& obj2) {
	std::string frame = "-----------------------------------------------------------------------------------------------------\n";
	std::string titles [] = {"Names", "Hit Points", "Energy Points", "Attack Damage"};
	ScavTrap scav("Scav_example");
	FragTrap frag("Frag_example");
	std::cout << frame;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[0] \
				<< "|" << std::setw(19) << scav \
				<< "|" << std::setw(19) << frag \
				<< "|" << std::setw(19) << obj1 \
				<< "|" << std::setw(19) << obj2 \
				<< "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[1] \
				<< "|" << std::setw(19) << scav.getInt("hit") \
				<< "|" << std::setw(19) << frag.getInt("hit") \
				<< "|" << std::setw(19) << obj1.getInt("hit") \
				<< "|" << std::setw(19) << obj2.getInt("hit") \
				<< "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[2] \
				<< "|" << std::setw(19) << scav.getInt("energy") \
				<< "|" << std::setw(19) << frag.getInt("energy") \
				<< "|" << std::setw(19) << obj1.getInt("energy") \
				<< "|" << std::setw(19) << obj2.getInt("energy") \
				<< "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(19) << titles[3] \
				<< "|" << std::setw(19) << scav.getInt("attack") \
				<< "|" << std::setw(19) << frag.getInt("attack") \
				<< "|" << std::setw(19) << obj1.getInt("attack") \
				<< "|" << std::setw(19) << obj2.getInt("attack") \
				<< "|" << std::endl;
	std::cout << frame;
}


