/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/01 22:42:39 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWSED_HPP
#define NEWSED_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#define SUCCESS 0
#define FAIL 1

class NewSed {
	public:
		NewSed(const std::string& filename, const std::string& str1, const std::string& str2);
		~NewSed(void);
		void		setter();
		std::string	getter() const;
		int			openFile(void);

	private:
		std::string _file;
		std::string	_s1;
		std::string	_s2;
};

#endif