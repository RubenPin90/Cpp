/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:15:29 by rpinchas          #+#    #+#             */
/*   Updated: 2024/05/02 17:26:40 by rpinchas         ###   ########.fr       */
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
        void    getContact(void);

    private:
        std::string firstn;
        std::string lastn;
        std::string nickn;
        std::string phone;
        std::string secret;
};


#endif