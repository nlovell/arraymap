#pragma once
#include <stddef.h>
#include <array>
#include <iostream>
#include <string>

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

	/* The array of pointers to Keys to be used within the Map. */
	K *keyArray = new K[capacity];

	/* The array of pointers to Values to be used within the Map. */
	V *valArray = new V[capacity];

public:

	/************************************************************************************
	Removes all values and resets the map to it's default state non-destructively.
		All data pointed to within the map is *not* removed.
	************************************************************************************/
	void reset()
	{
		capacity = 1;
		lnth = 0;
		delete[] keyArray;
		delete[] valArray;
		keyArray = new K[capacity];
		valArray = new V[capacity];
	};

	bool isEmpty(){
		if(lnth<=0){
			return true;
		} else {
			return false;
		}
	};

	/************************************************************************************
	 Gets the present capacity of the array.
		@return		int				- the capacity of the array
	************************************************************************************/
	int getCapacity()
	{
		return capacity;
	};

	/************************************************************************************
	 Gets the number of items stored in the map.
		@return		int				- the capacity of the array
	************************************************************************************/
	int getLength()
	{
		return lnth;
	};

	/************************************************************************************
	 Inserts a new key-value pair into the map, if the key provided is unique
		 @param		K, theKey		- the key to identify the value
	 				V, theValue		- the value to insert
		 @return	bool			- 
	************************************************************************************/
	bool insert(K key, V value)
	{
		if (keyExists(key))
		{
			return false;
		} else {
			if (lnth + 1 == capacity)
			{
				enlargeMap();
			}

			lnth++;
			keyArray[lnth] = *new K(key);
			valArray[lnth] = *new V(value);
		};
	};

	/************************************************************************************
	 Inserts a new key-value pair into the map if unique, or updates an existing value
		 @param		K, theKey		- the key to identify the value
	 				V, theValue		- the value to insert
	************************************************************************************/
	void insertOrUpdate(K key, V value)
	{
		if (!insert(key, value))
		{
			updatePair(key, value);
		}
	};

	/************************************************************************************
	Removes a key-value pair based on the key
		@param		K, theKey		- the key to remove
	************************************************************************************/
	int removePair(K theKey)
	{

		int index = getIndex(theKey);

		int insert = 0;
		int newCapacity = capacity;
		if (capacity < lnth / 2)
		{
			newCapacity = capacity / 2;
		}

		//std::cout << "Attempting to remove item from array" << std::endl;

		//create smaller arrays
		K *tempKeyA = new K[newCapacity];
		V *tempValA = new V[newCapacity];

		//Iterate through old array length
		for (int i = 0; i < capacity; i++)
		{
			//std::cout << insert << " <- insert index" << std::endl;
			//std::cout << i << " <- fetch index" << std::endl;

			//Skip copying the item to remove
			if (i == index)
			{
				lnth--;
				//std::cout << "Item to remove skipped at index " << index << std::endl;
			}
			else
			{
				//copy across values to the new arrays
				K key = keyArray[i];
				V val = valArray[i];

				//std::cout << "Copying " << val << " to " << key << std::endl;
				tempKeyA[insert] = key;
				tempValA[insert] = val;
				insert++;
			}

			//destroy the old arrays.
			delete[] keyArray;
			delete[] valArray;

			//assign new arrays as the old arrays
			valArray = tempValA;
			keyArray = tempKeyA;

			//std::cout << "Deletion didn't fail" << std::endl;
			return capacity;
		}

		//If all else fails, return -1
		return -1;
	};

	/************************************************************************************
	 Updates a key-value pair based on the key
		@param		K, theKey		- the key to identify the value
					V, theValue		- the value to update
		@return		bool			- true if values updated
	************************************************************************************/
	bool updatePair(K theKey, V theValue)
	{
		valArray[getIndex(theKey)] = theValue;
		return true;
	};

	/************************************************************************************
	 Checks if a key exists in current key array
	 	@param		K, theKey		- the key to check
	 	@return		bool			- return true if theKey exists
	************************************************************************************/
	bool keyExists(K theKey)
	{
		//Iterate through array length
		for (int i = 0; i < capacity; i++)
		{
			if (theKey == keyArray[i])
			{
				//std::cout << "Key found in current key set. Skipping insert." << std::endl;
				return true;
			}
		}
		//std::cout << "Key not found in current key set. Attempting insertion." << std::endl;
		return false;
	};

	/************************************************************************************
	 Checks if a value exists in current key array
	 	@param		V, value		- the value to check
	 	@return		bool			- return true if value is present
	************************************************************************************/
	bool valueExists(V value)
	{
		if (getValuePointer == nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	};

	/************************************************************************************
	 Gets the pointer for a value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V*				- the pointer to return, or null
	************************************************************************************/
	V *getValuePointer(K key)
	{
		return &valArray[getIndex(key)];

		if (getIndex(key) != 0)
		{
			V *vt = &valArray[getIndex(key)];
			return vt;
		};
		return nullptr;
	};

	/************************************************************************************
	 Gets the value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V				- the value to return, or null
	************************************************************************************/
	V getValue(K key)
	{
		return *getValuePointer(key);
	}

	/************************************************************************************
	 Gets the value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V				- the value to return, or null
	************************************************************************************/
	V getValueOrDefault(K key, V default)
	{
		V *valP = getValuePointer(key);
		if (valP == nullptr)
		{
			return default;
		}
		else
		{
			return *getValuePointer(key);
		}
	};

	/************************************************************************************
	 Gets the index of a given key
		@param		K, key			- The key to find the index of.
		@return		int				- The index of the key, or -1 if not available.
	************************************************************************************/
	int getIndex(K key)
	{
		//std::cout << "Seaching for " << key << std::endl;

		//Iterates through the keyArray
		for (int i = 0; i != capacity; i++)
		{
			//std::cout << "index " << i << " : " << keyArray[i] << std::endl;
			//If it finds the key, return the associated value
			if (keyArray[i] == key)
			{
				//std::cout << "Value found at index " << i << std::endl;
				return i;
			}
		}
		//If key not found in the array, return null
		//std::cout << "Value not found. Maybe it was deleted by mistake?" << std::endl;
		return -1;
	};

	/************************************************************************************
	 Enlarge the size of both Key and Value arrays by one
	 	@return		int				- new size of map
	************************************************************************************/
	int enlargeMap()
	{
		//std::cout << "Attempting to embiggen array" << std::endl;

		std::cout << "Old array size: " << capacity - 1 << "." << std::endl;

		// incremented
		int inc = capacity + capacity;

		//create larger arrays
		K *tempKeyA = new K[inc];
		V *tempValA = new V[inc];
		for (int i = capacity - lnth; i < lnth; i++)
		{
			//copy across values to the new arrays
			//K key = keyArray[i];
			//V val = valArray[i];
			if (getValuePointer(keyArray[i]))
			{
				std::cout << "Copying " << valArray[i] << " to index " << i << " (" << keyArray[i] << ")" << std::endl;
				tempKeyA[i] = keyArray[i];
				tempValA[i] = valArray[i];
			}
		}

		// increment array size
		capacity = inc;

		//destroy the old arrays.
		delete[] keyArray;
		delete[] valArray;

		//assign new arrays as the old arrays
		valArray = tempValA;
		keyArray = tempKeyA;

		std::cout << " New array size: " << capacity - 1 << std::endl;
		//std::cout << "Embiggening didn't fail" << std::endl;
		return capacity;
	};

	/************************************************************************************
	Prints the contents of the array to the console.
	************************************************************************************/
	void print()
	{
		std::cout << "Printing contents of the map as [key:value] pairs. " << std::endl;
		if (lnth > 0)
		{
			for (int i = 1; i <= lnth; i++)
			{
				V *ref = getValuePointer(keyArray[i]);
				if (ref != nullptr)
				{
					V derefVal = *ref;
					std::cout << "[" << keyArray[i] << ":" << derefVal << "], ";
				}
				else
				{
					//std::cout << "NULL" << " : " << "NULL" << std::endl;
				}
			}
			std::cout << "\b\b " << std::endl;
		}
		else
		{
			std::cout << "The keymap is empty, and as such no printable values are stored." << std::endl;
		}
	};
};