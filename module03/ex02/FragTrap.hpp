/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:17:52 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/26 11:42:13 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#define FRAG_HIT_MAX 100
#define FRAG_NRG_MAX 100
#define FRAG_DMG_PNT 30

class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& ref);
		~FragTrap(void);
		FragTrap& operator=(const FragTrap& rhs);

		void highFivesGuys(void);

};

#endif
