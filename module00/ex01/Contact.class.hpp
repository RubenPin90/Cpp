/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:15:29 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/16 18:15:58 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
#include <iostream>
#include <string>

class Contact {
    public:
        Contact(void);
        ~Contact(void);
        void    setContact(void);
        void    getContact(void) const;

    private:
        std::string _firstn;
        std::string _lastn;
        std::string _nickn;
        std::string _phone;
        std::string _secret;
};

#endif