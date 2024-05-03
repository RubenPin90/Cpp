/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:33:22 by rpinchas          #+#    #+#             */
/*   Updated: 2023/12/27 21:33:23 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ft_transform(char *arg) {
	for (int i = 0; arg[i]; i++)
		if (arg[i] >= 'a' && arg[i] <= 'z')
			arg[i] -= 32;
	std::cout << arg;
}

int main(int argc, char **argv) {
	if (argc >= 2) {
		for (int i = 1; i < argc; i++) {
			ft_transform(argv[i]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
