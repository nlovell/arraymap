#pragma once
#include <iostream>
#include "Keymap.h"
#include "ArrayLength.h"
int main() {

	std::cout << "yeet" << std::endl;
	Keymap<int, int>* km = new Keymap<int, int>;
	
	//Insert 1 and find it
	std::cout << "inserting 1:11" << std::endl;
	km->insertPair(1, 11);
	std::cout << km->getValue(1) << std::endl;
	
	//Insert 2, and find both 1 and 2
	std::cout << "inserting 2:22" << std::endl;
	km->insertPair(2, 22);
	std::cout << km->getValue(1) << std::endl;
	std::cout << km->getValue(2) << std::endl;
	
	//Insert 3, and find 1, 2, and 3
	std::cout << "inserting 3:33" << std::endl;
	km->insertPair(3, 33);
	std::cout << km->getValue(1) << std::endl;
	std::cout << km->getValue(2) << std::endl;
	std::cout << km->getValue(3) << std::endl;

	//Update 1 to 123
	km->updatePair(1, 123);
	std::cout << km->getValue(1) << std::endl;
	std::cout << km->getValue(2) << std::endl;
	std::cout << km->getValue(3) << std::endl;



};

