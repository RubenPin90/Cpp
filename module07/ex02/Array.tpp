#define DEFAULT 0

template<typename T>
Array<T>::Array() : _data(NULL), _size(DEFAULT) {
	std::cout << "Array default constructor called.\n";
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	std::cout << "Array constructor with unsigned int parameter called.\n";
	this->_data = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& ref) : _size(ref.size()) {
	std::cout << "Array copy constructor called.\n";
	this->_data = new T[ref._size]();
	for (unsigned int i = 0; i < _size; i++) {
		this->_data[i] = ref._data[i];
	}
}

template<typename T>
Array<T>::~Array() {
	std::cout << "Array destructor called with " << this->_size << " elements." << std::endl;
	delete [] this->_data;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
	if (this == &rhs)
		return *this;
	delete [] this->_data;
	this->_data = new T[rhs._size]();
	this->_size = rhs._size;
	for (unsigned int i = 0; i < rhs._size; i++) {
		this->_data[i] = rhs._data[i];
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= this->_size)
		throw std::out_of_range("Index is out of bounds.");
	return (this->_data[i]);
}

template<typename T>
const T& Array<T>::operator[](unsigned int i) const {
	if (i >= this->_size)
		throw std::out_of_range("Index is out of bounds.");
	return (this->_data[i]);
}

template<typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}
