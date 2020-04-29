#pragma once
#include <iostream>
#include <string>
#include "Keymap.h"
#include "Test.h"

using namespace std;

int main()
{

	int intArr[] =	 {  1,  2,  3,  4,  5};
	char charArr[] = { 'A','B','C','D','E'};

	KeymapTest<int, char> kmt = *new KeymapTest<int, char>;
	kmt.populate(intArr, charArr, 5);
}