#pragma once
#include <stddef.h>
#include <array>
template <typename K, typename V>
class Keymap
{
private:
	/* The capacity of the array */
	int capacity = 1;

	/* The length of the array*/
	int lnth = 0;

public:

	/* The array of Keys to be used within the Map */
	K* keyArray = new K[1];

	/* The array of Values to be used within the Map */
	V* valArray = new V[1];

public:


	/*
	 *	Method to insert a new key-value pair into the map
	 *	param:	K, theKey		- the key to identify the value
	 *			V, theValue		- the value to insert
	 */
	void insertPair(K key, V value) {
		if (lnth == capacity) {
			enlargeMap();
			std::cout << "EMBIGGEN" << std::endl;
		}
		try {
			int insertLoc = capacity - 1;
			keyArray[insertLoc] = key;
			valArray[insertLoc] = value;
			lnth++;
		}
		catch (...) {}
	};

	/*
	 *	Method to remove a key-value pair based on the key
	 *	param: K, theKey		- the key to remove
	 */
	void removePair(K theKey) {};

	/*
	 *	Method to update a key-value pair based on the key
	 *	param:	K, theKey		- the key to identify the value
	 *			V, theValue		- the value to update

	 *	return: bool			- true if values updated
	 */
	bool updatePair(K theKey, V theValue) {

		valArray[getIndex(theKey)] = theValue;

		return true;

	};


	/*
	 *	Method to get the value stored in the map based on the Key
	 *	param: K, key			- the key to identify the value
	 *	return: V				- the value to return, or null
	 */
	V getValue(K key) {
		if(getIndex(key)!=NULL)
				return valArray[getIndex(key)];
		return NULL;
	};

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
		return NULL;
	}

	/*
	 *	Method to ensure key does not exist in current key array
	 *	param:	k, theKey		- the key to check
	 *	return: bool			- return true if theKey is unique and valid
	 */
	bool checkKeyValue(K theKey) {
		return true;
	};

	/*
	 *	Method to shrink the size of both arrays by one
	 * 	return: int				- new size of map
	 */
	int shrinkMap() {
		capacity--;
		return 0;
	};
	
	/*
	 *	Method to enlarge the size of both arrays by one
	 *	return: int				- new size of map
	 */
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
};

