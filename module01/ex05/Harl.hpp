/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 00:01:56 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#define SUCCESS 0
#define FAIL 1

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void		setter();
		std::string	getter() const;

	private:


};

#endif