#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Keymap.h"

/************************************************************************************
	A class to manually test the map.

	Designed and implemented by Student 20107104674840, November 2019.
        Depends on the Catch2 Test framework. 
        Catch2 can be found here: https://github.com/catchorg/Catch2/
        The catch.hpp file can be found at https://tinyurl.com/ussa7h6
*************************************************************************************/

TEST_CASE("Keymaps with Int:Chars", "[int:char]")
{
    Keymap<int, char> *km = new Keymap<int, char>;
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());

    int cap1 = km->getCapacity();
    km->enlargeMap();
    int cap2 = km->getCapacity();
    REQUIRE(cap1 < cap2);

    REQUIRE(km->insert(1, 'a') == true);
    REQUIRE(km->getValue(1) == 'a');

    REQUIRE(km->insert(1, 'z') == false);
    REQUIRE(km->getValue(1) == 'a');

    km->updatePair(1, 'A');
    REQUIRE(km->getValue(1) == 'A');

    REQUIRE(km->insertOrUpdate(1, 'z') == false);
    REQUIRE(km->getValue(1) == 'z');

    REQUIRE(km->insertOrUpdate(2, 'b') == true);
    REQUIRE(km->getValue(1) == 'z');
    REQUIRE(km->getValue(2) == 'b');
    REQUIRE(km->getLength() == 2);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->insert(3, 'c');
    REQUIRE(km->getValue(1) == 'z');
    REQUIRE(km->getValue(2) == 'b');
    REQUIRE(km->getValue(3) == 'c');
    REQUIRE(km->getLength() == 3);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->removePair(1);
    REQUIRE(km->getValue(2) == 'b');
    REQUIRE(km->getValue(3) == 'c');
    REQUIRE(km->getLength() == 2);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->reset();
    REQUIRE(km->getCapacity() == 1);
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());
};
