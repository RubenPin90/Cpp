#include "RPN.hpp"


RPN::RPN(const std::string& input) : _neg_num(1) {
	if (input.empty() || input.find_first_not_of(" "))
		throw std::runtime_error("Invalid input: String is empty.");
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::runtime_error("Invalid characters found in string.");

	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		std::string::const_iterator next;
		if (*it == ' ') 
			continue;
		if (std::isdigit((*it))) {
			next = it + 1;
			if (*next != ' ' && *next != '\0')
				throw std::runtime_error("Operand doesn't stand alone.");
			_baseStack.push((*it - '0') * _neg_num);
			_neg_num = 1;
		} else if (isOperator(*it)) {
			next = it + 1;
			if (*it == '-' && isdigit(*next)) {
				_neg_num = -1;
				continue;
			}
			if (_baseStack.size() < 2)
				throw std::runtime_error("Not enough numbers.");
			if (*next != ' ' && *next != '\0')
				throw std::runtime_error("Operator doesn't stand alone.");
			long right = _baseStack.top();
			_baseStack.pop();
			switch (*it) {
				case '+':
					_baseStack.top() += right;
					break;
				case '-':
					_baseStack.top() -= right;
					break;
				case '*':
					_baseStack.top() *= right;
					break;
				case '/':
					if (right == 0)
						throw std::runtime_error("Division with 0 not possible.");
					_baseStack.top() /= right;
					break;
				default:
					break;
			}
			if (_baseStack.top() > std::numeric_limits<int>::max() || _baseStack.top() < std::numeric_limits<int>::min())
				throw std::runtime_error("Overflow detected. Oh..no..Aborting!");
		}
	}
	if(_baseStack.size() > 1) 
		throw std::runtime_error("Not enough operators to compute result.");
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

bool RPN::isOperator(char c) {
	return (c == '-' || c == '+' || c == '*' || c == '/');
}

long RPN::getResult() {
	return _baseStack.top();
}

void RPN::printStackData() {
	std::stack<long, std::vector<long> > tempStack = _baseStack;
	while (!tempStack.empty()) {
		std::cout << tempStack.top() << " " << std::endl;
        tempStack.pop();
    }
}

