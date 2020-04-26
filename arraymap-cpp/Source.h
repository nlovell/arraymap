#pragma once
#include <iostream>
#include <string>
#include "Keymap.h"
#include "Test.h"

using namespace std;

int main()
{

	int intArr[] = { 1,2,3,4,5};
	char charArr[] = { 'A','B','C','D','E'};

	KeymapTest<int, char> kmt = *new KeymapTest<int, char>;
	kmt.populate(intArr, charArr, 5);
}

	void notMain(){
    Keymap < int, char > km = * new Keymap < int, char >;
        cout << "length " << km.getLength()<< endl;
    
        km.insert(1, 'a');
        km.insert(2, 'b');
        km.insert(3, 'c');
        km.insert(4, 'd');

        for(auto iter = km.begin(); iter!=km.end(); ++iter){
            cout << km.getValue(iter.operator*()) << endl;
        }
}