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

	const K NULLKEY;
	const V NULLVAL;

public:

	/************************************************************************************
	 Gets the present capacity of the array.
		@return		int				- the capacity of the array
	************************************************************************************/
	int getCapacity() {
		return capacity;
	};

	int getLength() {
		return lnth;
	};

	K setNulls(K nullKey, V nullVal) {
		NULLKEY = nullKey;
		NULLVAL = nullVal;
	}

	/************************************************************************************
	 Inserts a new key-value pair into the map
		 @param		K, theKey		- the key to identify the value
					V, theValue		- the value to insert
	************************************************************************************/
	void insertPair(K key, V value) {
		if (isKeyUnique(key)) {
			if (capacity == lnth + offset) {
				enlargeMap();
			}
			try {
				int insertLoc = getEmptyPosition();
				keyArray[insertLoc] = key;
				valArray[insertLoc] = value;
				lnth++;
			}
			catch (...) {
				std::cout << "There's an error lol glhf" << std::endl;
			}
		};
	};

	/************************************************************************************
	Asserts the first empty position in the array
		 @return	int				- the first empty position, or 0
	************************************************************************************/
	int getEmptyPosition() {
		//std::cout << "Looking for empty spaces." << std::endl;
		for (int i = 1; i < capacity; i++) {
			//std::cout << "Reading value of " << i << ": " << keyArray[i] << std::endl;
			if (keyArray[i] == NULLKEY) {
				std::cout << "Empty spaces found at index " << i << std::endl;
				return i;
			}
		}
		std::cout << "No empty space found.               :(" << std::endl;
		return NULL;
	};

	/************************************************************************************
	Removes a key-value pair based on the key
		@param		K, theKey		- the key to remove
	************************************************************************************/
	int removePair(K theKey) {

		int index = getIndex(theKey);

		keyArray[index] = NULLKEY;
		//valueArray[index] = NULL;

		return index;
		/*
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
			//decrement array size
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
		}*/
	};

	/************************************************************************************
	 Updates a key-value pair based on the key
		@param		K, theKey		- the key to identify the value
					V, theValue		- the value to update
		@return		bool			- true if values updated
	************************************************************************************/
	bool updatePair(K theKey, V theValue) {
		int index = getIndex(theKey);
		
		if (index > 0) {
			valArray[] = theValue;
			return true;
		}

		return false;
	};

	/************************************************************************************
	 Ensure a key does not exist in current key array
		@param		k, theKey		- the key to check
		@return		bool			- return true if theKey is unique and valid
	************************************************************************************/
	bool isKeyUnique(K theKey) {

		for (int i = 0; i < capacity; i++) {
			if (theKey == keyArray[i]) {
				return false;
			}
		}

		return true;
	};


	/************************************************************************************
	 Gets the value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V				- the value to return, or null
	************************************************************************************/
	V getValue(K key) {
		if (getIndex(key) != NULLKEY)
			return valArray[getIndex(key)];
		return NULLVAL;
	};

	/************************************************************************************
	 Gets the index of a given key
		@param		K, key			- The key to find the index of.
		@return		int				- The index of the key, or 0/NULL if not available.
	************************************************************************************/
	int getIndex(K key)
	{
		//Iterates through the keyArray
		for (int i = offset; i != capacity; i++) {
			//If it finds the key, return the associated value
			if (keyArray[i] == key) {
				return i;
			}
		}
		//If key not found in the array, return null
		std::cout << "Value not found. Maybe it was deleted by mistake?" << std::endl;
		return NULL;
	}

	/************************************************************************************
	 Enlarge the size of both Key and Value arrays by one
		@return		int				- new size of map
	************************************************************************************/
	int enlargeMap() {
		std::cout << "Attempting to embiggen array" << std::endl;

		// increment array size
		capacity = capacity * 2;

		//larger arrays (temporary)
		K* tempKeyA = new K[capacity];
		V* tempValA = new V[capacity];

		//prefill array with NULL
		std::fill_n(tempKeyA, capacity, NULLKEY);
		std::fill_n(tempValA, capacity, NULLVAL);
		
		//For the known number of elements in the array...	(cont)
		for (int j = offset; j <= lnth; j++) {
			//...in the entire capacity of the array...		(cont)
			for (int i = j; i < capacity; i++) {
				//...with non-null keys...					(cont)
				if (keyArray[i] != NULLKEY) {
					//...copy them across, and mark the original key as NULL.
					tempKeyA[j] = keyArray[i];
					tempValA[j] = valArray[i];
					keyArray[i] = NULLKEY;
					i = capacity;
				}
			}
		}

		//destroy the old arrays.
		delete[] keyArray;
		delete[] valArray;

		//assign new arrays as the old arrays
		valArray = tempValA;
		keyArray = tempKeyA;

		delete[] tempKeyA;
		delete[] tempValA;

		std::cout << "Embiggening didn't fail" << std::endl;
		return capacity;
	};
};
