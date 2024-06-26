/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:17:52 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/24 12:10:39 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#define SCAV_HIT_MAX 100
#define SCAV_NRG_MAX 50
#define SCAV_DMG_PNT 20

class ScavTrap : virtual public ClapTrap {
	public:
	//Constructors
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& ref);
	
	//Destructor/Deconstructor
		~ScavTrap(void);
	
	//Operator overload functions
		ScavTrap& operator=(const ScavTrap& rhs);

	//Public Methods
		void guardGate(void);
		virtual void attack(const std::string& target);

	//Getter

	//Setter

	private:
		void	m_initvalues(void);
		bool	m_guard;

};

#endif
