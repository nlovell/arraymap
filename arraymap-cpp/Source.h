#pragma once
#include <iostream>
#include "Keymap.h"
int main() {

	std::cout << "Test run!" << std::endl;
	Keymap<int, char>* intCharKeymap = new Keymap<int, char>;
	
	//Try and get a null value
	std::cout << "Null value: " << intCharKeymap->getValue(1) << std::endl;
	std::cout << std::endl;

	//Insert 1 and find it
	std::cout << "inserting 1:a" << std::endl;
	intCharKeymap->insertPair(1, 'a');
	std::cout << "Get val1: " << intCharKeymap->getValue(1) << std::endl;
	std::cout << std::endl;

	//Attempt to insert 1 again, and find it
	std::cout << "inserting 1:z" << std::endl;
	intCharKeymap->insertPair(1, 'z');
	std::cout << "Get val1: " << intCharKeymap->getValue(1) << std::endl;
	std::cout << std::endl;

	//Insert 2, and find both 1 and 2
	std::cout << "inserting 2:b" << std::endl;
	intCharKeymap->insertPair(2, 'b');
	std::cout << intCharKeymap->getValue(1) << std::endl;
	std::cout << intCharKeymap->getValue(2) << std::endl;
	std::cout << std::endl;

	//Insert 3, and find 1, 2, and 3
	std::cout << "inserting 3:c" << std::endl;
	intCharKeymap->insertPair(3, 'c');
	std::cout << intCharKeymap->getValue(1) << std::endl;
	std::cout << intCharKeymap->getValue(2) << std::endl;
	std::cout << intCharKeymap->getValue(3) << std::endl;
	std::cout << std::endl;

	//Update 1 to 123
	std::cout << "updating 1:a to 1:A" << std::endl;
	intCharKeymap->updatePair(1, 'A');
	std::cout << intCharKeymap->getValue(1) << std::endl;
	std::cout << intCharKeymap->getValue(2) << std::endl;
	std::cout << intCharKeymap->getValue(3) << std::endl;
	std::cout << std::endl;

	//Remove 1
	std::cout << "Removing 1:A" << std::endl;
	std::cout << " Capacity before removal: " << intCharKeymap->getCapacity() << std::endl;
	intCharKeymap->removePair(1);
	std::cout << " Capacity after removal: " << intCharKeymap->getCapacity() << std::endl;
	std::cout << "  Value 1: " << intCharKeymap->getValue(1) << std::endl;
	std::cout << "  Value 2: " << intCharKeymap->getValue(2) << std::endl;
	std::cout << "  Value 3: " << intCharKeymap->getValue(3) << std::endl;
	std::cout << std::endl;
};

