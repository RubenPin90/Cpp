/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:46:00 by rpinchas          #+#    #+#             */
/*   Updated: 2024/06/03 12:37:19 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewSed.hpp"
#define HIDDEN_FILE 0

NewSed::NewSed(const std::string& filename, const std::string& str1, const std::string& str2) \
		: _file(filename), _s1(str1), _s2(str2) {
}

NewSed::~NewSed(void) {
}

std::string NewSed::_createOutFile(std::string str) {
	if (str.empty())
		return "";
	size_t dotPos = str.find_last_of('.');
	if (dotPos != std::string::npos && dotPos != HIDDEN_FILE && dotPos != str.length()) {
		std::string suffix = str.substr(dotPos);
		str.erase(dotPos);
		str = str + "_replaced" + suffix;
	} else {
		str += "_replaced";
	}
	return str;
}

int	NewSed::openFiles(void) {
	this->_ifs.open(this->_file.c_str());
	if (!this->_ifs.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return FAIL;
	}
	std::string outFile = this->_createOutFile(this->_file);
	if (outFile.empty())
		return FAIL;
	this->_ofs.open((outFile).c_str());
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
