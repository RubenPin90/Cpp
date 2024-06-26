/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:23:41 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/28 02:00:35 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
#include "Contact.class.hpp"
#include <cstdlib>
#include <iomanip> 
#include <iostream>
#include <limits>

class   PhoneBook {
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add(void);
        void    search(void) const;
        int     ft_exit(void) const;
        void    printlist(void) const;


    private:
        Contact _people[8];
};

std::string trunc(std::string str);
int         checkinput(std::string check);

#endif

