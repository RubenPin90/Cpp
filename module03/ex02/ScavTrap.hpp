/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:17:52 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/24 12:09:38 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#define SCAV_HIT_MAX 100
#define SCAV_NRG_MAX 50
#define SCAV_DMG_PNT 20

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& ref);
		~ScavTrap(void);
		ScavTrap& operator=(const ScavTrap& rhs);

		void guardGate(void);
		void attack(const std::string& target);

	private:
		void	m_initvalues(void);
		bool	m_guard;

};

#endif
