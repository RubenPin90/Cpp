#include "Span.hpp"

#define DEFAULT 10

Span::Span() : _maxValues(DEFAULT), _vec(std::vector<int>()) {}
Span::Span(unsigned int value) : _maxValues(value), _vec(std::vector<int>()) {}
Span::Span(const Span& ref) : _maxValues(ref._maxValues), _vec(std::vector<int>(ref._vec)) {}
Span::~Span() {}
Span& Span::operator=(const Span& rhs) {
	if (this == &rhs)
		return *this;
	this->_maxValues = rhs._maxValues;
	this->_vec = std::vector<int>(rhs._vec);
	return *this;
}

void Span::addNumber(unsigned int num) throw(std::out_of_range) {
	if (this->_vec.size() == this->_maxValues)
		throw (std::out_of_range("Can't add more element: Span is full."));
	this->_vec.push_back(num);
}

unsigned int Span::shortestSpan() const throw(std::out_of_range) {
	if (_vec.size() < 2) {
		throw (std::out_of_range("Not enough elements to search."));
	}
	std::vector<int> tmp_vec = this->_vec;
	std::sort(tmp_vec.begin(), tmp_vec.end());
	unsigned int dist = std::numeric_limits<unsigned int>::max();
	for (v_cit it = tmp_vec.begin(); it != tmp_vec.end() - 1; ++it) {
		unsigned int tmp = *(it + 1) - *it;
		dist = std::min(dist, tmp);
	}
	return dist;
}

unsigned int Span::longestSpan() const throw(std::out_of_range) {
	if (_vec.size() < 2) {
		throw (std::out_of_range("Not enough elements to search."));
	}
	unsigned int min_value = *std::min_element(_vec.begin(), _vec.end());
	unsigned int max_value = *std::max_element(_vec.begin(), _vec.end());
	return max_value - min_value;
}

void Span::addMulti(v_cit begin, v_cit end) throw(std::invalid_argument, std::out_of_range){
	unsigned int dist = std::distance(begin, end);
	if (!dist)
		throw std::invalid_argument("Wrong input of iterators.");
	if ((this->_vec.size() + dist) > this->_maxValues)
		throw std::out_of_range("Can't add numbers: Range too large for the span.");
	this->_vec.insert(this->_vec.end(), begin, end);
}

