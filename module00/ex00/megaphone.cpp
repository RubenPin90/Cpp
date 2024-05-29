/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:37:54 by rpinchas          #+#    #+#             */
/*   Updated: 2024/04/30 15:04:50 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void    ft_transform(std::string str) {
    for(int j = 0; str[j]; j++)
        std::cout << static_cast<char>(std::toupper(str[j]));
}

int    main (int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++)
            ft_transform(argv[i]);
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
