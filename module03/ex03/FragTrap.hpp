/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:17:52 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/22 13:34:52 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#define FRAG_HIT_MAX 100
#define FRAG_NRG_MAX 100
#define FRAG_DMG_PNT 30

class FragTrap : virtual public ClapTrap {
	public:
	//Constructors
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& ref);

	//Destructor/Deconstructor
		virtual ~FragTrap(void);

	//Operator overload functions
		FragTrap& operator=(const FragTrap& rhs);

	//Public Methods
		void highFivesGuys(void);
	
	//Getter

	//Setter

	private:
		bool	m_highfives;
};

#endif
