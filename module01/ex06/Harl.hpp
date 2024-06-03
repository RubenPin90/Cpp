/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 20:37:46 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#define SUCCESS 0
#define FAIL 1

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

#define MSG_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-\
special-ketchup burger. I really do!"
#define MSG_INFO "I cannot believe adding extra bacon costs more money. You didn't \
put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define MSG_WARNING "I think I deserve to have some extra bacon for free. I've been \
coming for years whereas you started working here since last month."
#define MSG_ERROR "This is unacceptable! I want to speak to the manager now."
#define nLevels 4

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void 		complain(std::string level);

	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
	
		typedef	void (Harl::*PFnComplains[])(void);
};

#endif