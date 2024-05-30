/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 21:49:24 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	int size = 3;

	Zombie*	newhorde = zombieHorde(size, "Braineater");
	for (int i = 0; i < size; i++)
		newhorde[i].announce();
	delete [] newhorde;
	return (0);
}