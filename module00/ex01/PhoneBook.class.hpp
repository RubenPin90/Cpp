/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:23:41 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/03 14:08:36 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
#include "Contact.class.hpp"

class   PhoneBook {
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void    add(void);
        void    search(void);
        int     exit(void) const;

    private:
        Contact _people[8];
};

#endif

