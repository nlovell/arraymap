#pragma once
#include <iostream>
#include <string>
#include "Keymap.h"
#include "Test.h"

using namespace std;

int main()
{
	int intArr[] = { 1,  2,  3,  4,  5 };
	char charArr[] = { 'A','B','C','D','E' };
	bool boolArr[] = { 0,  1,  1,  0,  1 };
	float floatArr[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
	double doubArr[] = { 1.111, 1.222, 1.333, 1.444, 1.555 };
	string strArr[] = { "foo", "bar", "baz", "boo", "far" };

	KeymapTest<int, char> intChar = *new KeymapTest<int, char>;
	intChar.test(intArr, charArr, 5, 99);

	//KeymapTest<string, bool> strBool = *new KeymapTest<string, bool>;
	//strBool.test(strArr, boolArr, 5, false);

	KeymapTest<string, string> strStr = *new KeymapTest<string, string>;
	strStr.test(strArr, strArr, 5, "fizz");

	KeymapTest<double, float> doubFloat = *new KeymapTest<double, float>;
	doubFloat.test(doubArr, floatArr, 5, 6.345);

	KeymapTest<float, double> floatDoub = *new KeymapTest<float, double >;
	floatDoub.test(floatArr, doubArr, 5, 6.345);
}