/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/17 12:01:48 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#define SUCCESS 0
#define FAIL 1
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class ClapTrap {
	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& ref);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& rhs);
		
		
		std::string	getName(void) const;
		int			getInt(const std::string& value) const;
		bool		getBool(void) const;
		void 		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void 		beRepaired(unsigned int amount);

	protected:
		std::string m_name;
		int			m_hit;
		int			m_energy;
		int			m_attack;
		bool		m_failure;
};

std::ostream& operator<<(std::ostream& ost, const ClapTrap& rhs);

#endif
