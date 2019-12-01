#pragma once
#include <stddef.h>
#include <array>

/*
	A class to map key:value pairs, built upon static C++ arrays.
	types:	K			- The type of Key to be used
			V			- The type of Value to be used
	Designed and implemented by Student 20107104674840, November 2019.
*/
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

	/*
	 *	Gets the present capacity of the array.
	 *	return:	int				- the capacity of the array
	 */
	int getCapacity() {
		return capacity;
	};

	/*
	 *	Method to insert a new key-value pair into the map
	 *	param:	K, theKey		- the key to identify the value
	 *			V, theValue		- the value to insert
	 */
	void insertPair(K key, V value) {
		if (lnth+1 == capacity) {
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
	 *	param:	K, theKey		- the key to remove
	 */
	int removePair(K theKey) {
	
		int index = getIndex(theKey);

		//Index 0 is always empty, as it equates to NULL.
		if (index > 0) {
			int insert = 0;
			int newCapacity = capacity - 1;

			std::cout << "Attempting to remove item from array" << std::endl

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

	/*
	 *	Method to update a key-value pair based on the key
	 *	param:	K, theKey		- the key to identify the value
	 *			V, theValue		- the value to update
	 *
	 *	return: bool			- true if values updated
	 */
	bool updatePair(K theKey, V theValue) {

		valArray[getIndex(theKey)] = theValue;

		return true;

	};


	/*
	 *	Method to get the value stored in the map based on the Key
	 *	param: K, key			- the key to identify the value
	 *
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
	 *
	 *	return: bool			- return true if theKey is unique and valid
	 */
	bool checkKeyValue(K theKey) {
		return true;
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

