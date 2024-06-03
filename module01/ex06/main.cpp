/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 21:03:24 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string   ft_transform(std::string str) {
    std::string new_str;

	for(std::string::iterator it = str.begin(); it != str.end(); it++)
        new_str += static_cast<char>(std::toupper(*it));
	return new_str;
}

int main(int ac, char *av[]) {
	
	if (ac != 2) {
		std::cerr << "Wrong input!\n";
		std::cout << "Usage: ./harlFilter <Complain>";
		return FAIL;
	}
	std::string str;
	Harl harl;
	str = ft_transform(av[1]);
	harl.complain(str);
}
