#pragma once
#include <iostream>
#include <string>
#include "Keymap.h"
#include "Test.h"

using namespace std;


/************************************************************************************
	Main class.
	Designed and implemented by Student 20107104674840.
*************************************************************************************/
int main()
{
	int count = 10;

	//Arrays to store default data to run tests on
	int intArr[] =   {  1,  2,  3,  4,  5,  6,  7,  8,  9, 10};
	char charArr[] = { 'A','B','C','D','E','F','G','H','I','J'};
	bool boolArr[] = {  0,  1,  1,  0,  1,  0,  0,  1,  0,  1 };
	float floatArr[] = { 0.14754676f, 0.24754676f, 0.34754676f, 0.44754676f, 0.54754676f,
						 0.64754676f, 0.74754676f, 0.84754676f, 0.94754676f, 0.104754676f };
	double doubArr[] = { 1.111, 1.222, 1.333, 1.444, 1.555, 1.666, 1.777, 1.888, 1.999, 1.10101 };
	string strArr[] = { "foo", "bar", "baz", "boo", "far", 
						"fizz", "buzz", "bizz", "fuzz", "fozz"};

	//Default values for getValueOrDefault() method
	int defInt = 99;
	char defChar = 'Z';
	bool defBool = false;
	float defFloat = 9.123453f;
	double defDoub = 999.999;
	string defString = "Default.";


	//Runs the KeymapTest with K:V types Int:Char
	KeymapTest<int, char> intChar = *new KeymapTest<int, char>;
	intChar.test(intArr, charArr, count, defInt);

	//Runs the KeymapTest with K:V types String:Bool
	KeymapTest<string, bool> strBool = *new KeymapTest<string, bool>;
	strBool.test(strArr, boolArr, count, defBool);

	//Runs the KeymapTest with K:V types String:String
	KeymapTest<string, string> strStr = *new KeymapTest<string, string>;
	strStr.test(strArr, strArr, count, defString);

	//Runs the KeymapTest with K:V types Double:Float
	KeymapTest<double, float> doubFloat = *new KeymapTest<double, float>;
	doubFloat.test(doubArr, floatArr, count, defFloat);

	//Runs the KeymapTest with K:V types Float:Double
	KeymapTest<float, double> floatDoub = *new KeymapTest<float, double >;
	floatDoub.test(floatArr, doubArr, count, defDoub);
}