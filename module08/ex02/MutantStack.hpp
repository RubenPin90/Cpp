#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

//std::stack has a std::deque as its underlying container by default
// it is possible to change it by providing a second template argument for MutantStack
template<typename T, typename subContainer = std::deque<T> >
class MutantStack : public std::stack<T, subContainer> {
	public:
		typedef std::stack<T, subContainer> baseStack;

		MutantStack() : baseStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack& ref) : baseStack(ref) {}
		MutantStack& operator=(const MutantStack& rhs) {
			if (this == &rhs)
				return *this;
			baseStack::operator=(rhs);
			return *this;
		}
		// could also use this approach: this->c = other.c; 
		//directly assigns the underlying container (c)

		typedef typename subContainer::iterator iterator;
		typedef typename subContainer::const_iterator const_iterator;
		//a more general approach would be: 
		//typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		const_iterator cbegin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator cend() { return this->c.end(); }
};


#endif
