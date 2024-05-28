/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:35:51 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/28 01:26:48 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

int     Contact::ft_isvalid(std::string str) const {
	int n = str.length();
	bool valid = false;
	
	if (str.empty())
		return (1);
	for (int i = 0; i < n; i++) {
		if (std::isalnum(str[i]))
			valid = true;
		else if (!std::isspace(str[i])) {
			std::cout << "Used invalid characters. Try again.\n";
			return (1);
		}
	}
	if (!valid) {
		std::cout << "Empty String. Try again.\n";
		return (1);
	}
	return (0);
}

void    Contact::setContact(void) {
	std::string input[5];
	std::string question[5] = {"First name:", "Last name:", "Nickname:", \
								"Phone number:", "Darkest secret:"};
	
	std::cout << "<Adding new contact>\n" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << question[i] << "\n";
		if (!std::getline(std::cin >> std::ws, input[i])) 
			break;
		input[i] = rmws(input[i]);
		if (i == 3 && onlydigit(input[i])) {
			std::cout << "Ups wrong phonenr. Only numbers accepted. Try again.\n";
			i--;
		} else if (ft_isvalid(input[i]))
			i--;
	}
	_firstn = input[0];
	_lastn = input[1];
	_nickn = input[2];
	_phone = input[3];
	_secret = input[4];
}

void    Contact::getContact(void) const {
	std::cout << "First name: " << _firstn << "\n";
	std::cout << "Last name: " << _lastn << "\n";
	std::cout << "Nickname: " << _nickn << "\n";
	std::cout << "Phone Number: " << _phone << "\n";
	std::cout << "Darkest Secret: " << _secret << std::endl;
}

std::string    Contact::getInfo(std::string str) const {
	if (str == "firstname")
		return (_firstn);
	else if (str == "lastname")
		return (_lastn);
	else if (str == "nickname")
		return (_nickn);
	else if (str == "phone")
		return (_phone);
	else if (str == "secret")
		return (_secret);
	else
		return (NULL);
}

