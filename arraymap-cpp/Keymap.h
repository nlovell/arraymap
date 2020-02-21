#pragma once
#include <stddef.h>
#include <array>
#include <iostream>

/************************************************************************************
	A class to map key:value pairs, built upon static C++ arrays.
	@types		K					- The type of Key to be used
				V					- The type of Value to be used
	Designed and implemented by Student 20107104674840, November 2019.
*************************************************************************************/
template <typename K, typename V>
class Keymap
{
private:
	/* The capacity of the array. */
	int capacity = 1;

	/* The length of the array. */
	int lnth = 0;

	/* The permanent offset for writing to the array. */
	const int offset = 1;

	/* The array of Keys to be used within the Map. */
	K* keyArray = new K[1];

	/* The array of Values to be used within the Map. */
	V* valArray = new V[1];


public:

	/************************************************************************************
	 Gets the present capacity of the array.
		@return		int				- the capacity of the array
	************************************************************************************/
	int getCapacity() {
		return capacity;
	};

	/************************************************************************************
	 Inserts a new key-value pair into the map
		 @param		K, theKey		- the key to identify the value
	 				V, theValue		- the value to insert
	************************************************************************************/
	void insertPair(K key, V value) {
		if (isKeyUnique(key)) {
			if (lnth + 1 == capacity) {
				enlargeMap();
				std::cout << "EMBIGGEN" << std::endl;
			}
			try {
				int insertLoc = capacity - 1;
				keyArray[insertLoc] = * new K(key);
				valArray[insertLoc] = * new V(value);
				lnth++;
			}
			catch (...) {}
		};
	};

	/************************************************************************************
	Removes a key-value pair based on the key
		@param		K, theKey		- the key to remove
	************************************************************************************/
	int removePair(K theKey) {
	
		int index = getIndex(theKey);

		//Index 0 is always empty, as it equates to NULL.
		if (index > 0) {
			int insert = 0;
			int newCapacity = capacity - 1;

			std::cout << "Attempting to remove item from array" << std::endl;

			//create smaller arrays
			K* tempKeyA = new K[newCapacity];
			V* tempValA = new V[newCapacity];

			//Iterate through old array length
			for (int i = 0; i < capacity; i++) {
				std::cout << insert << " <- insert index" << std::endl;
				std::cout << i << " <- fetch index" << std::endl;

				//Skip copying the item to remove
				if (i == index) {
					std::cout << "Item to remove skipped at index " << index << std::endl;
				}
				else {
					//copy across values to the new arrays
					K key = keyArray[i];
					V val = valArray[i];

					std::cout << "Copying " << val << " to " << key << std::endl;
					tempKeyA[insert] = key;
					tempValA[insert] = val;
					insert++;
				}
			}
			// decrement array size
			capacity = newCapacity;
			lnth--;

			//destroy the old arrays.
			delete[] keyArray;
			delete[] valArray;

			//assign new arrays as the old arrays
			valArray = tempValA;
			keyArray = tempKeyA;

			std::cout << "Deletion didn't fail" << std::endl;
			return capacity;
		}
	};

	/************************************************************************************
	 Updates a key-value pair based on the key
		@param		K, theKey		- the key to identify the value
					V, theValue		- the value to update
		@return		bool			- true if values updated
	************************************************************************************/
	bool updatePair(K theKey, V theValue) {
		valArray[getIndex(theKey)] = theValue;
		return true;
	};

	/************************************************************************************
	 Ensure a key does not exist in current key array
	 	@param		k, theKey		- the key to check
	 	@return		bool			- return true if theKey is unique and valid
	************************************************************************************/
	bool isKeyUnique(K theKey) {
		//Iterate through array length
		for (int i = 0; i < capacity; i++) {
			if (theKey == keyArray[i]) {
				std::cout << "Key found in current key set. Skipping insert." << std::endl;
				return false;
			}
		}
		std::cout << "Key not found in current key set. Attempting insertion." << std::endl;
		return true;
	};


	/************************************************************************************
	 Gets the value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V				- the value to return, or null
	************************************************************************************/
	V * getValue(K key) {
		if (getIndex(key) != NULL) {
			V* vt = &valArray[getIndex(key)];

			return vt;
		}
		return nullptr;
	};

	/************************************************************************************
	 Gets the index of a given key
		@param		K, key			- The key to find the index of.
		@return		int				- The index of the key, or 0/NULL if not available.
	************************************************************************************/
	int getIndex(K key)
	{
		std::cout << "Seaching for " << key << std::endl;

		//Iterates through the keyArray
		for (int i = 0; i != capacity; i++) {
			//std::cout << "index " << i << " : " << keyArray[i] << std::endl;
			//If it finds the key, return the associated value
			if (keyArray[i] == key) {
				std::cout << "Value found at index " << i << std::endl;
				return i;
			}
		}
		//If key not found in the array, return null
		std::cout << "Value not found. Maybe it was deleted by mistake?" << std::endl;
		return -1;
	}

	/************************************************************************************
	 Enlarge the size of both Key and Value arrays by one
	 	@return		int				- new size of map
	************************************************************************************/
	int enlargeMap() {
		std::cout << "Attempting to embiggen array" << std::endl;

		// increment array size
		capacity++;						

		//create larger arrays
		K *tempKeyA = new K[capacity];
		V *tempValA = new V[capacity];
		for (int i = 0; i < capacity-1; i++) {

			//copy across values to the new arrays
			K key = keyArray[i];			
			V val = valArray[i];

			std::cout << "Copying " << val << " to " << key << std::endl;
			tempKeyA[i] = key;
			tempValA[i] = val;
		}

		//destroy the old arrays.
		delete[] keyArray;
		delete[] valArray;

		//assign new arrays as the old arrays
		valArray = tempValA;
		keyArray = tempKeyA;

		std::cout << "Embiggening didn't fail" << std::endl;
		return capacity;
	};


	/************************************************************************************
	Prints the contents of the array to the console.
	************************************************************************************/
	void print() {
		std::cout << "Printing contents of the map as [key:value] pairs. " << std::endl;

		for (int i = 0; i != capacity; i++) {
			V *val1 = getValue(keyArray[i]);
			if (val1 == nullptr) {
				std::cout << "Nullptr returned at index " << i << std::endl;
			}
			else {
				V val2 = *val1;
				std::cout << keyArray[i] << " : " << val2 << std::endl;

			}
		}
	}
};