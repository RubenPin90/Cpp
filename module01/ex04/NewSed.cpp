/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/01 23:21:21 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewSed.hpp"

NewSed::NewSed(const std::string& filename, const std::string& str1, const std::string& str2) \
		: _file(filename), _s1(str1), _s2(str2) {
}

NewSed::~NewSed(void) {
}

void		NewSed::setter(void) {
}

std::string		NewSed::getter(void) const {
	return "";
}

int	NewSed::openFile(void) {
	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open(_file.c_str());
	if (!ifs.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
	}
	ofs.open("output");
	if (!ofs.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
		ifs.close();
    	return 1;
	}
	std::string line;
	std::stringstream tmp;
	while (std::getline(ifs, line)) {
		tmp << line << '\n';
	}
	line = tmp.str();
	size_t	needlePos = 0;
	while (needlePos != std::string::npos) {
		needlePos = line.find(_s1);
		if (needlePos != std::string::npos) {
			std::cout << line << std::endl;
			line.erase (needlePos, _s1.length());
			line.insert (needlePos, _s2);
		}
	}
	ofs << line;
	ifs.close();
	ofs.close();
	return 0;
}
