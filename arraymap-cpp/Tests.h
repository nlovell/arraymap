#pragma once
#include <iostream>
#include <string>

/************************************************************************************
	A class to manually test the map.

	Designed and implemented by Student 20107104674840, November 2019.
*************************************************************************************/

void testTitle(std::string test) {
	std::cout << std::endl << "==============================" <<
	std::endl << std::endl << "TEST: " << test << std::endl;
}

void testIntCharKeymap() {
	std::cout << "Testing features with Int:Char keymap!" << std::endl;
	Keymap<int, char> * intCharKeymap = new Keymap<int, char>;

	//------------------------------------

	//Print the first value of an empty array
	testTitle("Print the first value of an empty array");
	char var = *intCharKeymap->getValue(1);
	std::cout << "Null value: " << var << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------

	//Insert 1 and find it
	testTitle(" Insert value A against 1, and find it.");
	std::cout << "inserting 1:a" << std::endl;
	intCharKeymap->insertPair(1, 'a');
	std::cout << "Get val1: " << *intCharKeymap->getValue(1) << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------

	//Attempt to insert 1 again, and find it
	testTitle("Attempt to insert against Key 1 again, and find it");
	std::cout << "inserting 1:z" << std::endl;
	intCharKeymap->insertPair(1, 'z');
	std::cout << "Get val1: " << *intCharKeymap->getValue(1) << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------


	//Insert 2, and find both 1 and 2
	testTitle("Insert B against 2, then find both 1 and 2");
	std::cout << "inserting 2:b" << std::endl;
	intCharKeymap->insertPair(2, 'b');
	std::cout << *intCharKeymap->getValue(1) << std::endl;
	std::cout << *intCharKeymap->getValue(2) << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------

	//Insert 3, and find 1, 2, and 3
	testTitle("Insert C against 3, then find all three");
	std::cout << "inserting 3:c" << std::endl;
	intCharKeymap->insertPair(3, 'c');
	std::cout << *intCharKeymap->getValue(1) << std::endl;
	std::cout << *intCharKeymap->getValue(2) << std::endl;
	std::cout << *intCharKeymap->getValue(3) << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------

	//Update 1 from a to A
	testTitle("Update 1:a to 1:A");
	std::cout << "updating 1:a to 1:A" << std::endl;
	intCharKeymap->updatePair(1, 'A');
	std::cout << *intCharKeymap->getValue(1) << std::endl;
	std::cout << *intCharKeymap->getValue(2) << std::endl;
	std::cout << *intCharKeymap->getValue(3) << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------

	//Remove 1
	testTitle("Remove pair 1:A");
	std::cout << "Removing 1:A" << std::endl;
	std::cout << " Capacity before removal: " << intCharKeymap->getCapacity() << std::endl;
	intCharKeymap->removePair(1);
	std::cout << " Capacity after removal: " << intCharKeymap->getCapacity() << std::endl;
	std::cout << "  Value 1: " << *intCharKeymap->getValue(1) << std::endl;
	std::cout << "  Value 2: " << *intCharKeymap->getValue(2) << std::endl;
	std::cout << "  Value 3: " << *intCharKeymap->getValue(3) << std::endl;
	std::cout << std::endl;

	//Print the whole array
	intCharKeymap->print();

	//------------------------------------

	//Add everything
	testTitle("Add just a whole bunch of stuff");
	//intCharKeymap->removePair(2);
	//intCharKeymap->removePair(3);
	//Print the whole array
	intCharKeymap->print();

	for(int i = 0; i <= 126; i++){
		intCharKeymap->insertOrUpdate(i, char(i));
		std::cout << * intCharKeymap->getValue(i) << std::endl;
	}

	//Print the whole array
	intCharKeymap->print();
	
	//------------------------------------

	//Remove everything
	testTitle("Remove just a whole bunch of stuff");
	//intCharKeymap->removePair(2);
	//intCharKeymap->removePair(3);
	//Print the whole array
	int contents = intCharKeymap->getLength();
	
	for(int i = 0; i <= 120; i++){
		intCharKeymap->removePair(i);
	}

	std::cout << "Started with " << contents << " and ended with " << intCharKeymap->getLength() << std::endl;

	//Print the whole array
	intCharKeymap->print();
	
	//------------------------------------
};

void testStringStringKeymap(){
std::cout << "Testing features with String:String keymap!" << std::endl;
	Keymap<std::string, std::string> * km = new Keymap<std::string, std::string>;

	testTitle(" Insert value \"Yes\" against \"No\", and find it.");
	km->insertPair("Yes", "No");
	km->insertPair("Maybe", "Idk");
	//km->insertPair("Can", "you");
	//km->insertPair("Repeat", "the");
	//km->insertPair("Question","..?");
	//km->insertPair("YOU'RE NOT THE BOSS OF ME NOW", "YOU'RE NOT THE BOSS OF ME NOW");
	std::cout << "Get Yes: " << *km->getValue("Yes") << std::endl;
	std::cout << std::endl;
	km->print();
};