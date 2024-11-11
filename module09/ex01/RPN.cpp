#include "RPN.hpp"

RPN::RPN(const std::string& input) {
	// Add securities, like:
	// - Operator check in the front Error
	// - False Operants (only numbers under 10)
	// - false input Error (no symbols).
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		std::string::const_iterator next;
		if (*it == ' ') 
			continue;
		if (std::isdigit((*it))) {
			next = it + 1;
			if (*next != ' ')
				throw std::runtime_error("Operand doesn't stand alone.");
			_baseStack.push(*it - '0');
		} else if (isOperator(*it)) {
			if (_baseStack.size() < 2)
				throw std::runtime_error("Not enough numbers.");
			next = it + 1;
			if (*next != ' ' || *next != '\0')
				throw std::runtime_error("Operator doesn't stand alone.");
			long num = _baseStack.top();
			_baseStack.pop();
			switch (*it) {
				case '+':
					_baseStack.top() += num;
					break;
				case '-':
					_baseStack.top() -= num;
					break;
				case '*':
					_baseStack.top() *= num;
					break;
				case '/':
					if (num == 0)
						throw std::runtime_error("Division with 0 not possible.");
					_baseStack.top() /= num;
					break;
				
			}
		}
	}
	printStackData();
}
RPN::~RPN() {}
RPN::RPN(const RPN& ref) { *this = ref; }
RPN& RPN::operator=(const RPN& rhs) {
	if(this == &rhs)
		return *this;
	this->_baseStack = rhs._baseStack;
	return *this;
}


static bool isOperator(char c) {
	return (c == '-' || c == '+' || c == '*' || c == '/');
}

void RPN::printStackData() {
	std::stack<long, std::vector<long> > tempStack = _baseStack;
	while (!tempStack.empty()) {
		std::cout << tempStack.top() << " " << std::endl;
        tempStack.pop();
    }
}

// static void	trim(std::string& str) {
// 	const char* whitespace = " ";
// 	std::size_t start = str.find_first_not_of(whitespace);
// 	std::size_t end = str.find_last_not_of(whitespace);
// 	if (start != end)
// 		str = str.substr(start, end - start + 1);
// }

