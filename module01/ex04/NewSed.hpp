/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 23:45:43 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/12 09:51:52 by rpinchas         ###   ########.fr       */
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
		NewSed(char* filename, const std::string& str1, const std::string& str2);
		~NewSed(void);
		int			openFiles(void);
		int			transferAndReplace(void);

	private:
		std::string _createOutFile(std::string str);
		std::string _file;
		std::string	_s1;
		std::string	_s2;
		std::ifstream _ifs;
		std::ofstream _ofs;
};

#endif