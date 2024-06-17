/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/16 00:14:04 by rpinchas         ###   ########.fr       */
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

		// Assignment operator overload:
		Fixed& operator=(const Fixed& rhs);

		// Comparison operator overload:
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		// Arithemtic operator overload:
		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		// Increment/decrement operator overload:
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		int			toInt(void) const;
		float 		toFloat(void) const;
		int			getRawBits(void) const;
		void		setRawBits(int i);
		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static const Fixed& min(const Fixed& num1, const Fixed& num2);
		static const Fixed& max(const Fixed& num1, const Fixed& num2);
		
	private:
		int 			 _value;
		static const int _frac_bits = 8;
};

std::ostream& operator<<(std::ostream& ost, const Fixed& rhs);

#endif