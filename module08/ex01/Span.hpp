#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

typedef std::vector<int>::const_iterator v_cit;

class Span {
	public:
		Span();
		Span(unsigned int value);
		Span(const Span &ref);
		Span& operator=(const Span &rhs);
		~Span();

		void addNumber(unsigned int num) throw(std::out_of_range);
		unsigned int shortestSpan() const throw(std::out_of_range);
		unsigned int longestSpan() const throw(std::out_of_range);
		void addMulti(v_cit begin, v_cit end) throw(std::invalid_argument, std::out_of_range);

	private:
		unsigned int _maxValues;
		std::vector<int> _vec;
};

#endif
