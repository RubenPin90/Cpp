#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <vector>
#include <limits>
#include <sstream>

#define FAIL 1
#define SUCCESS 0

class RPN {
	public:
		RPN(const std::string& input);
		RPN(const RPN& ref);
		~RPN();
		RPN& operator=(const RPN& rhs);
		long getResult();
		
	private:
		std::stack<long, std::vector<long> > _baseStack;
		int _neg_num;
		void printStackData();
		bool isOperator(char c);
};

#endif
