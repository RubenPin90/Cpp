/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/17 12:01:28 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
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
		Fixed(const int i);
		Fixed(const float fl);
		~Fixed(void);
		Fixed& operator=(const Fixed& rhs);

		int			toInt(void) const;
		float 		toFloat(void) const;
		int			getRawBits(void) const;
		void		setRawBits(int i);

	private:
		int 			 _value;
		static const int _frac_bits = 8;
};

std::ostream& operator<<(std::ostream& ost, const Fixed& rhs);

#endif
