#pragma once
#include <stddef.h>
#include <array>
#include <iostream>
#include <string>
#include "Keymap.h"

/************************************************************************************
	A class to map key:value pairs, built upon static C++ arrays.
	@types		K					- The type of Key to be used
				V					- The type of Value to be used
	Designed and implemented by Student 20107104674840, November 2019.
*************************************************************************************/

//The iterator needs to be forward-declared.
template <typename K, typename V>
class MapIter;

//A happy little Keymap template
template <typename K, typename V>
class Keymap
{
private:
	//Every template needs a
	friend class MapIter<K, V>;

	MapIter<K, V>* beginPtr;
	MapIter<K, V>* endPtr;

	/* The capacity of the array. */
	int capacity = 1;

	/* The length of the array. */
	int lnth = 0;

	/* The array of pointers to Keys to be used within the Map. */
	K* keyArray = new K[capacity];

	/* The array of pointers to Values to be used within the Map. */
	V* valArray = new V[capacity];

public:

	Keymap(){
		beginPtr = new MapIter<K, V>(*this, 0);
		endPtr = new MapIter<K, V>(*this, lnth);
	}

	/************************************************************************************
	Removes all values and resets the map to it's default state non-destructively.
		No data pointed to within the map is removed.
	************************************************************************************/
	void reset()
	{
		capacity = 1;
		lnth = 0;
		updateEnd();

		delete[] keyArray;
		delete[] valArray;
		keyArray = new K[capacity];
		valArray = new V[capacity];
	};

	/************************************************************************************
	Returns true if the length of the array is zero (or less).
		@return		bool			- true if length <=0
	************************************************************************************/
	bool isEmpty()
	{
		if (lnth <= 0)
		{
			return true;
		}
		else
		{
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
		}
		else
		{
			if (lnth == capacity)
			{
				enlargeMap();
			}

			keyArray[lnth] = *new K(key);
			valArray[lnth] = *new V(value);
			lnth++;
			updateEnd();

			//std::cout<< "Length: " << lnth << " | Val: " << value << std::endl;
			return true;
		};
	};

	void updateEnd() {
		delete endPtr;
		endPtr = new MapIter<K, V>(*this, lnth);
	}

	/************************************************************************************
	 Inserts a new key-value pair into the map if unique, or updates an existing value
		 @param		K, theKey		- the key to identify the value
					V, theValue		- the value to insert
		 @return	Returns True if inserted, False if updated.
	************************************************************************************/
	bool insertOrUpdate(K key, V value)
	{
		bool test = insert(key, value);
		if (!test)
		{
			updatePair(key, value);
			test = false;
		}
		return test;
	};

	/************************************************************************************
	Removes a key-value pair based on the key
		@param		K, theKey		- the key to remove
	************************************************************************************/

	bool removePair(K theKey)
	{
		int newCapacity = capacity;
		if (lnth < capacity / 2)
		{
			newCapacity = (capacity / 2);
			if (newCapacity < 1)
			{
				newCapacity = 1;
			}
		}

		//create smaller arrays
		K* tempKeyA = new K[newCapacity];
		V* tempValA = new V[newCapacity];

		if (keyExists(theKey))
		{
			lnth--;
			updateEnd();

			int j = 0;
			for (int i = 0; i < capacity; i++)
			{
				if (keyArray[i] != theKey)
				{
					tempKeyA[j] = keyArray[i];
					tempValA[j] = valArray[i];
					j++;
				}
			}

			//destroy the old arrays.
			delete[] keyArray;
			delete[] valArray;

			keyArray = tempKeyA;
			valArray = tempValA;
			capacity = newCapacity;

			return true;
		}

		return false;
	}

	/************************************************************************************
	 Updates a key-value pair based on the key
		@param		K, theKey		- the key to identify the value
					V, theValue		- the value to update
		@return		bool			- true if values updated
	************************************************************************************/
	bool updatePair(K theKey, V theValue)
	{
		if (keyExists(theKey)) {
			valArray[getIndex(theKey)] = theValue;
			return true;
		}
		return false;
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
		for (int i = 0; i < lnth; i++)
		{
			if (valArray[i] == value)
			{
				return true;
			}
		}

		return false;
	};

	/************************************************************************************
	 Gets the pointer for a value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V*				- the pointer to return, or null
	************************************************************************************/
	V* getValuePointer(K key)
	{
		return &valArray[getIndex(key)];

		if (getIndex(key) != -1)
		{
			V* vt = &valArray[getIndex(key)];
			return vt;
		};
		return nullptr;
	};

	V* getValuePointerAtIndex(int index) {

		return &valArray[index];
	}

	/************************************************************************************
	 Gets the value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V				- the value to return, or null
	************************************************************************************/
	V getValue(K key)
	{
		return *getValuePointer(key);
	};

	V getValueAtIndex(int index)
	{
		return valArray[index];
	}

	V getValue(K* keyPointer)
	{
		return *keyPointer;
	};

	/************************************************************************************
	 Gets the value stored in the map for a given Key
		@param		K, key			- the key to identify the value
		@return		V				- the value to return, or null
	************************************************************************************/
	V getValueOrDefault(K key, V dflt)
	{
		if (keyExists(key)
			)
		{
			return getValue(key);
		}
		else
		{
			return dflt;
		}
	};

	/************************************************************************************
	 Gets the index of a given key
		@param		K, key			- The key to find the index of.
		@return		int				- The index of the key, or -1 if not available.
	************************************************************************************/
	int getIndex(K key)
	{
		//Iterates through the keyArray
		for (int i = 0; i <= capacity; i++)
		{
			//If it finds the key, return the associated value
			if (keyArray[i] == key)
			{
				return i;
			}
		}
		return -1;
	};

	K getKeyAtIndex(int index) {
		return keyArray[index];
	}

	/************************************************************************************
	 Enlarge the size of both Key and Value arrays by one
		@return		int				- new size of map
	************************************************************************************/
	int enlargeMap()
	{
		//std::cout << "Attempting to embiggen array" << std::endl;
		//std::cout << "Old array size: " << capacity - 1 << "." << std::endl;

		// incremented
		int inc = capacity + capacity;

		//create larger arrays
		K* tempKeyA = new K[inc];
		V* tempValA = new V[inc];
		for (int i = 0; i < lnth; i++)
		{
			//copy across values to the new arrays
			//K key = keyArray[i];
			//V val = valArray[i];
			// (getValuePointer(keyArray[i]))
			//{
				//std::cout << "Copying " << valArray[i] << " to index " << i << " (" << keyArray[i] << ")" << std::endl;
			tempKeyA[i] = keyArray[i];
			tempValA[i] = valArray[i];
			//}
		}

		// increment array size
		capacity = inc;

		//destroy the old arrays.
		delete[] keyArray;
		delete[] valArray;

		//assign new arrays as the old arrays
		valArray = tempValA;
		keyArray = tempKeyA;

		return capacity;
	};

	/************************************************************************************
	Prints the contents of the array to the console.
	************************************************************************************/
	void print()
	{
		//std::cout << "Printing contents of the map as [key:value] pairs. " << std::endl;
		if (lnth > 0)
		{
			for (int i = 0; i < lnth; i++)
			{
				V* ref = getValuePointer(keyArray[i]);
				if (ref != nullptr)
				{
					V derefVal = *ref;
					std::cout << "[" << keyArray[i] << ":" << derefVal << "], ";
				}
				else
				{
					std::cout << "NULL"
						<< " : "
						<< "NULL" << std::endl;
				}
			}
			std::cout << "\b\b " << std::endl;
		}
		else
		{
			std::cout << "The keymap is empty, and as such no printable values are stored." << std::endl;
		}
	};

	MapIter<K, V> & begin()
	{
		return *beginPtr;
	}

	MapIter<K, V> & end()
	{
		return *endPtr;
	}

	bool operator==(Keymap<K, V> & km)
	{
		/*
		int i = 0;
		for (const K& key : keyArray) {
			if (!(km.keyArray[i] == key && km.valArray[i] == this.valArray[i])) {
				return false;
			}
			i++;
		} */
		return true;	
	}

	bool operator!=(Keymap<K, V> & km) {
		return !(operator==(km));
	}

	~Keymap()
	{
		delete[] keyArray;
		delete[] valArray;
		delete endPtr;
		delete beginPtr;
	}
};

template <typename K, typename V>
class MapIter
{
private:
	Keymap<K, V>& km;
	int index;
public:
	MapIter<K, V>(Keymap<K, V>& keymap, int kmIndex)
		: km(keymap), index(kmIndex)
	{}

	MapIter<K, V>& operator++()
	{
		++index;
		return *this;
	}

	MapIter<K, V>& operator--()
	{
		--index;
		return *this;
	}

	bool operator==(MapIter<K, V> & rhs)
	{
		return ((*this).km == rhs.km) && ((*this).index == rhs.index);
	}

	bool operator!=(MapIter<K, V> & rhs)
	{
		return !(operator==(rhs));
	}

	K operator*()
	{
		return km.getKeyAtIndex(index);
	}
};