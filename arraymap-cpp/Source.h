#pragma once
#include <iostream>
#include <string>
#include "Keymap.h"
#include "Test.h"

using namespace std;

int main()
{


	int intArr[] =   {  1,  2,  3,  4,  5 };
	char charArr[] = { 'A','B','C','D','E'};
	bool boolArr[] = {  0,  1,  1,  0,  1 };
	string strArr[] = { "foo", "bar", "baz", "boo", "far"};

	KeymapTest<int, char> intChar = *new KeymapTest<int, char>;
	intChar.test(intArr, charArr, 5, 99);


	KeymapTest<string, bool> strBool = *new KeymapTest<string, bool>;
	strBool.test(strArr, boolArr, 5, false);
}