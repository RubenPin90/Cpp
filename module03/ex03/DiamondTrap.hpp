/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:17:52 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/23 19:04:19 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& ref);
		virtual ~DiamondTrap(void);
		DiamondTrap&  operator=(const DiamondTrap& rhs);

		void	whoAmI(void);
		std::string	getName(void) const;

	private:
		std::string	m_name;
};

std::ostream& operator<<(std::ostream& ost, const DiamondTrap& rhs);

#endif
