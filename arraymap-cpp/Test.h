#pragma once
#include <stddef.h>
#include <array>
#include <iostream>
#include <string>
#include "Keymap.h"

/************************************************************************************
	A class to test the map.
	@types		K					- The type of Key to be used
				V					- The type of Value to be used
	Designed and implemented by Student 20107104674840, November 2019.
*************************************************************************************/

//A happy little Keymap template
template <typename K, typename V>
class KeymapTest
{
public:
	KeymapTest() {}

	void populate(K kArr[], V vArr[], int len) {
		Keymap <K, V> km = *new Keymap <K, V>;

		int ind = 0;
		while (ind < len) {
			km.insert(kArr[ind], vArr[ind]);
			ind++;
		}

		km.print();

		for (auto iter = km.begin(); iter != km.end(); ++iter) {
			std::cout << km.getValue(iter.operator*()) << std::endl;
		}
	}

};