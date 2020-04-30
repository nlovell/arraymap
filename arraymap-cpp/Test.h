#pragma once
#include <stddef.h>
#include <array>
#include <iostream>
#include <string>
#include "Keymap.h"
#include <typeinfo>

/************************************************************************************
	A class to test the map.
	@types		K					- The type of Key to be used
				V					- The type of Value to be used
	Designed and implemented by Student 20107104674840.
*************************************************************************************/

template <typename K, typename V>
class KeymapTest
{

public:

	Keymap <K, V> km = *new Keymap <K, V>;

	void test(K kArr[], V vArr[], int len, V valDef) {

		std::cout << "   MAP KEY TYPE: " << typeid(K).name() << std::endl << " MAP VALUE TYPE: " << typeid(V).name() << std::endl << std::endl;

		//Testing empty
		printTestNoBefore("Checking map is blank", "isEmpty", "True");
		std::cout << km.isEmpty() << std::endl;
		ma();

		//Test insert NULL key
		printTest("Attempting KEY insert using nullptr keyword", "insert(nullptr,v)", "Empty map");
		km.insert(nullptr, vArr[0]);
		ma();

		//Test insert NULL value
		printTest("Attempting VALUE insert using NULL keyword", "insert(k,nullptr)", "Empty map");
		km.insert(kArr[0], nullptr);
		ma();

		//Test insert both NULL key and value
		printTest("Attempting VALUE and KEY insert using NULL keyword", "insert(k,nullptr)", "Empty map");
		km.insert(nullptr, nullptr);
		ma();

		//Testing not empty
		printTest("Attempting to populate map using values", "insert(K,V), isEmpty()", "Populated array");
		//Loading the dataset.
		for (int i = 0; i < len; i++) {
			K ki = kArr[i];
			V va = vArr[i];
			km.insert(ki, va);
		}
		km.isEmpty();
		ma();

		//Reinsertion
		printTest("Attempting to reinsert data", "insert(K,V)", "Set should return the same as above, with no additions");
		for (int i = 0; i < len; i++) {
			K ki = kArr[i];
			V va = vArr[i];
			km.insert(ki, va);
		}
		ma();

		//Reinsertion
		printTest("Attempting to reinsert data using pointers", "insert(K,V)", "Set should return the same as above, with no additions");
		for (int i = 0; i < len; i++) {
			K* kip = &kArr[i];
			V* vap = &vArr[i];
			km.insert(kip, vap);
		}
		ma();

		//Test the iterator forwardly
		printTestNoBefore("Run the iterator forward", "Iterator", "1, 2, 3 (etc)");
		for (MapIter<K,V> iterator = km.begin();  iterator  != km.end(); ++iterator) {
			std::cout << "[" << *iterator << ":" << km.getValue(*iterator) << "], ";
		}
		std::cout << "\b\b  " << std::endl;
		ma();


		//Test the iterator backwardly
		printTestNoBefore("Run the iterator backward", "Iterator", "(etc), 3, 2, 1");
		for (MapIter<K, V> iterator = km.beginR(); iterator != km.endR(); --iterator) {
			std::cout << "[" << *iterator << ":" << km.getValue(*iterator) << "], ";
		}
		std::cout << "\b\b  " << std::endl;
		ma();

		//for (auto iter = km.begin(); iter != km.end(); ++iter) {
		//	std::cout << km.getValue(iter.operator*()) << std::endl;
		//}

		printTestNoBefore("Printing each value", "getValue(K)", "Each value is printed to the console.");
		std::cout << "[";
		for (int i = 0; i < len; i++) {
			std::cout << "[" << km.getValue(kArr[i]) << "], ";
		}
		std::cout << "\b\b  " << std::endl;
		ma();

		//Update a pair
		printTest("Updating a pair", "updatePair(K,V)", "Value at position 0 will be updated");
		km.updatePair(kArr[0], vArr[len-1]);
		ma();

		//Delete a pair
		printTest("Removing a pair", "removePair(K)", "Pair at position 0 will be removed");
		km.removePair(kArr[0]);
		ma();

		//Update a removed pair - nothing should happen
		printTest("Updating a non-existing pair", "updatePair(K,V)", "Before and after remain the same.");
		km.updatePair(kArr[0], vArr[len - 1]);
		ma();

		//Insert/Update !(exists)
		printTest("Updating/Inserting a non-existing pair", "insertOrUpdate(K,V)", "A new pair will be inserted at the end");
		km.insertOrUpdate(kArr[0], vArr[len - 1]);
		ma();

		//Get Value or Default !(exists)
		printTestNoBefore("Getting the value if exists, or a default value", "getValueOrDefault(K,default)", "");
		std::cout << km.getValueOrDefault(kArr[0], valDef);
		std::cout << std::endl;
		ma();

		//Insert/Update (exists)
		printTest("Updating/Inserting an existing pair", "insertOrUpdate(K,V)", "The new pair should be updated");
		km.insertOrUpdate(kArr[0], vArr[0]);
		ma();

		//Get Value or Default (exists)
		printTestNoBefore("Getting the value if exists, or a default value", "getValueOrDefault(K,default)", "");
		std::cout << km.getValueOrDefault(kArr[0], valDef);
		std::cout << std::endl;
		ma();
		
		//Get capacity
		printTestNoBefore("Get capacity", "getCapacity()", "Capacity >= number of elements");
		std::cout << km.getCapacity() << std::endl;
		ma();

		//Test the reset function
		printTest("Reset the Map", "reset()", "Map should be empty");
		km.reset();
		ma();

		//Testing not empty
		printTest("Attempting to populate map using pointers", "insert(K,V), isEmpty()", "Populated array");
		//Loading the dataset.
		for (int i = 0; i < len; i++) {
			K* kip = &kArr[i];
			V* vap = &vArr[i];
			km.insert(kip, vap);
		}
		km.isEmpty();
		ma();

		std::cout << std::endl << "---------------------------------------------------" << std::endl << std::endl;
	}

	void printTest(std::string test, std::string func, std::string expected) {
		std::cout << "        TESTING: " << test << std::endl;
		std::cout << "       FUNCTION: " << func << std::endl;
		std::cout << "EXPECTED RESULT: " << expected << std::endl;
		std::cout << "     MAP BEFORE: ";
		km.print();
	}

	void printTestNoBefore(std::string test, std::string func, std::string expected) {
		
		std::cout << "        TESTING: " << test << std::endl;
		std::cout << "       FUNCTION: " << func << std::endl;
		std::cout << "EXPECTED RESULT: " << expected << std::endl;
		std::cout << "         RESULT: ";
	}

	void ma() {
		std::cout << "      MAP AFTER: "; 
		km.print();
		std::cout << std::endl;
	}

};