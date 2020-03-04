#pragma once
#include <iostream>
#include <string>
#include "Keymap.h"

using namespace std;
/************************************************************************************
	A basic class to prove basic functionality of the map.

	Designed and implemented by Student 20107104674840, November 2019.
        Refer to the catch2_test.cpp file for more thorough testing.
*************************************************************************************/
int main()
{
    Keymap < int, char > * km = new Keymap < int, char >;
        cout << "length " << km->getLength()<< endl;
    
        km->insert(1, 'a');
        cout << km->getValue(1)<< endl;

        km->insert(1, 'z');
        cout << "1:" << km->getValue(1)<< endl;

        km->updatePair(1, 'A');
        cout <<"1:" << km->getValue(1)<< endl;

         km->insertOrUpdate(1, 'z');
        cout << "1:" <<km->getValue(1)<< endl;

        km->insertOrUpdate(2, 'b');
        cout <<"1:" << km->getValue(1)<< endl;
        cout <<"2:" << km->getValue(2)<< endl;
    
        km->insert(3, 'c');
        cout <<"1:" << km->getValue(1)<< endl;
        cout <<"2:" << km->getValue(2) << endl;
        cout <<"3:" << km->getValue(3)<< endl;
    
        km->removePair(1);
        //cout << km->getValuePointer(1) == nullptr)<< endl;
        cout << "2:" <<km->getValue(2)<< endl;
        cout << "3:" <<km->getValue(3)<< endl;
}
