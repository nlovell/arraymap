#pragma once
#include <iostream>
#include "Keymap.h"
int main() {

	std::cout << "Test run!" << std::endl;
	Keymap<int, char>* km = new Keymap<int, char>;
	
	//Try and get a null value
	std::cout << km->getValue(1) << std::endl;


	//Insert 1 and find it
	std::cout << "inserting 1:a" << std::endl;
	km->insertPair(1, 'a');
	std::cout << km->getValue(1) << std::endl;
	
	//Insert 2, and find both 1 and 2
	std::cout << "inserting 2:b" << std::endl;
	km->insertPair(2, 'b');
	std::cout << km->getValue(1) << std::endl;
	std::cout << km->getValue(2) << std::endl;
	
	//Insert 3, and find 1, 2, and 3
	std::cout << "inserting 3:c" << std::endl;
	km->insertPair(3, 'c');
	std::cout << km->getValue(1) << std::endl;
	std::cout << km->getValue(2) << std::endl;
	std::cout << km->getValue(3) << std::endl;

	//Update 1 to 123
	std::cout << "updating 1:a to 1:A" << std::endl;
	km->updatePair(1, 'A');
	std::cout << km->getValue(1) << std::endl;
	std::cout << km->getValue(2) << std::endl;
	std::cout << km->getValue(3) << std::endl;



};

