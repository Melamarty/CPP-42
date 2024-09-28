#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T *data;
		size_t _size;
	public:
		Array(): data(new T(NULL)), _size(0){};
		Array(unsigned int n): _size(n)
		{
			data = new T[n]();
			for (size_t i; i < _size; i++)
				data[i] = 0;
		}
		T& operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of range");
			}
			return data[index];
		}
		Array(const Array& other) {
			_size = other.size();
			data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i) {
				data[i] = other.data[i];
			}
		}

		 Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] data;
				_size = other.size();
				data = new T[_size];
				for (unsigned int i = 0; i < _size; ++i) {
					data[i] = other.data[i];
				}
			}
			return *this;
		}

		void display()
		{
			std::cout << "Array elements\n";
			for (size_t i = 0; i < _size; i++)
				std::cout << data[i] << std::endl;
		}
		size_t size() const
		{
			return (_size);
		};
		~Array() {
			delete [] data;
		};
};