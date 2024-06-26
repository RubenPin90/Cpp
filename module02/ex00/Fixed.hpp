/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/17 12:01:03 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#define SUCCESS 0
#define FAIL 1

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& ref);
		~Fixed(void);
		Fixed& operator=(const Fixed& rhs);
	
			int			getRawBits(void) const;
			void		setRawBits(int i);

	private:
		int 			 _value;
		static const int _frac_bits = 8;
};
	
#endif
