#include "Array.hpp"


int main() {
	std::cout << "Testing Array of integers:" << std::endl;
	Array<int> intArray(5); 

	std::cout << "Initial values in integer array: ";
	intArray.display();

	for (unsigned int i = 0; i < intArray.size(); ++i) {
		intArray[i] = i * 10;
	}

	std::cout << "Modified values in integer array: ";
	intArray.display();


	std::cout << "\nTesting Array of doubles:" << std::endl;
	Array<double> doubleArray(3);

	std::cout << "Initial values in double array: ";
	doubleArray.display();

	doubleArray[0] = 1.1;
	doubleArray[1] = 2.2;
	doubleArray[2] = 3.3;

	std::cout << "Modified values in double array: ";
	doubleArray.display();


	std::cout << "\nTesting copy constructor with integer array:" << std::endl;
	Array<int> intArrayCopy = intArray;  
	std::cout << "Copied integer array: ";
	intArrayCopy.display();

	std::cout << "\nTesting assignment operator:" << std::endl;
	Array<int> anotherArray(3);  
	anotherArray = intArray;

	std::cout << "Assigned integer array: ";
	anotherArray.display();

	return 0;
}
