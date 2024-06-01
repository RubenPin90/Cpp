/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/01 18:07:48 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewSed.hpp"

int main(int ac, char *av[]) {
	if (ac == 4) {
		NewSed sifl = NewSed(av[1], av[2], av[3]);
		sifl.openFile();
	} else {
		std::cerr << "Wrong input. Provide 3 arguments.\n" << std::endl;
		return FAIL;
	}
	return SUCCESS;
}