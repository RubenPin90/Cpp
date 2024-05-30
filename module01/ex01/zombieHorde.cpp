/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:33 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 19:43:37 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name) {
	Zombie*	zombies = new Zombie[n];

	for (int i = 0; i < n; i++)
		zombies[i].setname(name);
	
	return (zombies);
}