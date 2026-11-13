
template <typename T>
Array<T>::Array()
{
	_size = 1;
	_elements = new T[1]();
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_elements = new T[n];

	for (size_t i = 0; i < _size; i++)
		_elements[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	_size = other._size;
	_elements = new T[_size];

	for (size_t i = 0; i < _size; i++)
		_elements[i] = other._elements[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _elements;
		_size = other._size;
		_elements = new T[_size];

		for (size_t i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t n)
{
	if (n > _size)
	 throw OutOfBounds();
	return _elements[n];	
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
void Array<T>::printElements()
{
	for (size_t i = 0; i < _size; i++)
		std::cout << _elements[i] << "\n";
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return "Index is out of bounds";
}
