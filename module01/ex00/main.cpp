/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:30:50 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 13:16:09 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie* heap_zombie = newZombie("Heapy");
	randomChump("Stacky");
	heap_zombie->announce();
	delete heap_zombie;
	return (0);
}