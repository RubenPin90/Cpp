/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/02 23:36:01 by rpinchas         ###   ########.fr       */
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
	this->_ifs.open(this->_file.c_str());
	if (!this->_ifs.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return FAIL;
	}
	size_t dotPos = this->_file.find('.');
	std::string outFile = this->_file;
	if (dotPos != std::string::npos)
		outFile.erase(dotPos);
	this->_ofs.open((outFile + "_replaced.txt").c_str());
	if (!this->_ofs.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
		this->_ifs.close();
    	return FAIL;
	}
	return SUCCESS;
}

int NewSed::transferAndReplace(void) {
	std::string line;
	std::stringstream tmp;

	while (std::getline(this->_ifs, line)) {
		tmp << line << '\n';
	}
	line = tmp.str();
	size_t	needlePos = line.find(this->_s1);
	while (needlePos != std::string::npos) {
			line.erase(needlePos, this->_s1.length());
			line.insert(needlePos, this->_s2);
			needlePos = line.find(this->_s1, needlePos + this->_s2.length());
	}
	this->_ofs << line;
	this->_ifs.close();
	this->_ofs.close();
	return SUCCESS;
}
