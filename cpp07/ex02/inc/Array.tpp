/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharumi <naharumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:39:42 by naharumi          #+#    #+#             */
/*   Updated: 2025/07/23 09:39:42 by naharumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(other._size) {
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array(void) {
	delete [] _data;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete [] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return _size;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of range");
	return _data[index];
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& arr) {
	out << "{ ";
	for (unsigned int i = 0; i < arr.size(); i++) {
		out << arr[i];
		if (i < arr.size() - 1)
			out << ", ";
	}
	out << " }";

	return out;
}

#endif
