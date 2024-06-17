/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/16 00:13:34 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref) : _value(ref.getRawBits()) {
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _value(i << _frac_bits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fl) : _value(roundf(fl * (1 << _frac_bits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const {		
	return (_value >> _frac_bits);
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(_value) / static_cast<float>(1 << _frac_bits));
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assigment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int	Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

std::ostream& operator<<(std::ostream& ost, const Fixed& rhs) {
	ost << rhs.toFloat();
	return (ost);
}

bool Fixed::operator>(const Fixed& rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed& rhs) const {
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed& rhs) const {
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&	Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed&	Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	return (lhs < rhs ? lhs : rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	return (lhs > rhs ? lhs : rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	return (lhs < rhs ? lhs : rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	return (lhs > rhs ? lhs : rhs);
}