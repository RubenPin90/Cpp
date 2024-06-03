/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:15:23 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 12:23:38 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewSed.hpp"

void ft_close(NewSed* classToClose) {
	delete classToClose;
}

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Wrong input.\n";
		std::cerr << "Usage: " << av[0] << " <filename> <string1> <string2>\n";
		return FAIL;
	}
	NewSed* sifl = new NewSed(av[1], av[2], av[3]);
	if (sifl->openFiles() != SUCCESS)
		return (ft_close(sifl), FAIL);
	if (sifl->transferAndReplace() != SUCCESS)
		return (ft_close(sifl), FAIL);
	return (ft_close(sifl), SUCCESS);
}