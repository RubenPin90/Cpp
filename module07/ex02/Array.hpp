#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {
	public:
		Array();
		Array(T data)
		~Array();
	private:
		T* _data;
}


#endif