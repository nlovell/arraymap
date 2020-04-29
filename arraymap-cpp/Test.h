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

	void populate(K kArr[], V vArr[], const int len) {
		Keymap <K, V> km = *new Keymap <K, V>;

		for (int i = 0; i < len; i++) {
			K ki = kArr[i];
			V va = vArr[i];
			km.insert(ki, va);
		}

		for (int i = 0; i < len; i++) {
			//std::cout<< "Length: " << lnth << " | Val: " << value << std::endl;

			std::cout << km.getValue(kArr[i]) << std::endl;
		}


		km.print();
	}

};