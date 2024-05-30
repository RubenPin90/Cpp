/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:31:15 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 17:14:54 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private:
		std::string	_name;
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );

#endif