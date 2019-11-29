#pragma once
#include <stddef.h>

template <typename V>
class ArrayLength{

public:
	static int hxello(V inputArray)
{
	int count = 0;

	std::cout << "input value " << inputArray[count] << std::endl;

	// Printing elements of an array using foreach loop 
	while (inputArray[count]!=NULL) {
		std::cout << "input value " << inputArray[count] << std::endl;
		count++;
	}
	return count;
};
};