/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:06:30 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 21:49:59 by rpinchas         ###   ########.fr       */
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
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setname(std::string);
	private:
		std::string	_name;
		int	_id;
};

Zombie* zombieHorde( int N, std::string name );

#endif