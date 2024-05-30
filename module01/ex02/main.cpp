/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/30 23:37:42 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <iomanip>

void print(const std::string& str1, const std::string& str2, const std::string& str3) {
	std::cout << "|" << std::setfill(' ') << std::setw(19) << str1 \
			<< "|" << std::setw(19) << str2 \
			<< "|" << std::setw(19) << str3 << "|" << std::endl;
}

std::string	ptrtostr(void *ptr) {
	std::ostringstream tmp;
	tmp << ptr;
	return (tmp.str());
}

int main (void) {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string& stringREF = string;
	std::string frame = "-------------------------------------------------------------\n";
	
	std::cout << frame;
	print("Variable", "Memory address", "Value");
	std::cout << frame;
	print("string", ptrtostr(&string), string);
	print("stringPTR", ptrtostr(stringPTR), *stringPTR);
	print("stringREF", ptrtostr(&stringREF), stringREF);
	std::cout << frame;

	return (0);
}
