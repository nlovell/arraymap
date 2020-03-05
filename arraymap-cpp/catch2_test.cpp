#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Keymap.h"

/************************************************************************************
	A class to manually test the map.

	Designed and implemented by Student 20107104674840.
        Depends on the Catch2 Test framework. 
        Catch2 can be found here: https://github.com/catchorg/Catch2/
        The catch.hpp file can be found at https://tinyurl.com/ussa7h6
*************************************************************************************/

TEST_CASE("Stress testing - Add 10000 integers", "[int:int]")
{
    Keymap<int, int> *km = new Keymap<int, int>;

    int var = 10;
    for (int i = 0; i < var; i++)
    {
       km->insert(i,i);
    }

    REQUIRE(km->getLength() == var);

    for (int i = 0; i < var; i++)
    {
        REQUIRE(km->removePair(i) == true);
        REQUIRE(km->getValuePointer(i)!=nullptr);
    }

    REQUIRE(km->getLength() == 0);
    REQUIRE(km->getCapacity() < 5);

    km->reset();
    REQUIRE(km->getCapacity() == 1);
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());
}

TEST_CASE("Keymap with bool:double", "[bool:double]")
{
    Keymap<bool, double> *km = new Keymap<bool, double>;
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());

    int oldCap = km->getCapacity();
    REQUIRE(oldCap < km->enlargeMap());


    REQUIRE(km->insert(true, 100.01) == true);
    REQUIRE(km->getValue(true) == 100.01);
    REQUIRE(km->keyExists(true) == true);
    //Weird boolean witchcraft
    REQUIRE(km->keyExists(false) == true);

    REQUIRE(km->insert(true, 200.01) == false);
    REQUIRE(km->getValue(true) == 100.01);
    REQUIRE(km->getIndex(true) <= km->getCapacity());

    REQUIRE(km->getLength() == 1);
    REQUIRE(km->removePair(true) == true);
    REQUIRE(km->getLength() == 0);

    km->reset();
    REQUIRE(km->getCapacity() == 1);
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());

    REQUIRE(km->insertOrUpdate(true, 100.01) == true);
    REQUIRE(km->getValue(true) == 100.01);

    REQUIRE(km->insertOrUpdate(false, 200.01) == true);
    REQUIRE(km->getValue(false) == 200.01);

    REQUIRE(km->getValue(true) == 100.01);
    REQUIRE(km->keyExists(true) == true);
    REQUIRE(km->keyExists(false) == true);

    REQUIRE(km->insertOrUpdate(true, 1300.01) == false);
    REQUIRE(km->getValue(true) == 1300.01);

    REQUIRE(km->removePair(true) == true);
    REQUIRE(km->keyExists(true) == false);
    REQUIRE(km->removePair(true) == false);

    REQUIRE(km->getIndex(false) <= km->getCapacity());
};

TEST_CASE("Testing every method", "[int:char]")
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
    REQUIRE(km->getValuePointer(1) != nullptr);
    REQUIRE(km->getIndex(1) == 0);


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
    REQUIRE(km->getIndex(1) == 0);
    REQUIRE(km->getIndex(2) == 1);
    REQUIRE(km->getIndex(3) == 2);

    km->updatePair(3, 'C');
    REQUIRE(km->getValue(1) == 'z');
    REQUIRE(km->getValue(2) == 'b');
    REQUIRE(km->getValue(3) == 'C');
    
    REQUIRE(km->getValueOrDefault(1, 'G') == 'z');
    REQUIRE(km->valueExists('z'));
    REQUIRE(km->keyExists(1));
    km->removePair(1);
    REQUIRE(!km->keyExists(1));
    REQUIRE(!km->valueExists('z'));
    REQUIRE(km->getValueOrDefault(1, 'G') == 'G');
    REQUIRE(km->getIndex(1) == -1);
    REQUIRE(km->getIndex(2) == 0);

    REQUIRE(km->getValue(2) == 'b');
    REQUIRE(km->getValue(3) == 'C');
    REQUIRE(km->getLength() == 2);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->reset();
    REQUIRE(km->getCapacity() == 1);
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());

    km->~Keymap();
};

TEST_CASE("Keymaps with Float:Strings", "[int:string]")
{
    Keymap<float, std::string> *km = new Keymap<float, std::string>;
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());

    int cap1 = km->getCapacity();
    km->enlargeMap();
    int cap2 = km->getCapacity();
    REQUIRE(cap1 < cap2);

    REQUIRE(km->insert(1.1, "foo") == true);
    REQUIRE(km->getValue(1.1) == "foo");

    REQUIRE(km->insert(1.1, "Foo") == false);
    REQUIRE(km->getValue(1.1) == "foo");

    km->updatePair(1.1, "FOO");
    REQUIRE(km->getValue(1.1) == "FOO");

    REQUIRE(km->insertOrUpdate(1.1, "foo") == false);
    REQUIRE(km->getValue(1.1) == "foo");

    REQUIRE(km->insertOrUpdate(22.2, "bar") == true);
    REQUIRE(km->getValue(1.1) == "foo");
    REQUIRE(km->getValue(22.2) == "bar");
    REQUIRE(km->getLength() == 2);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->insert(333.3, "baz");
    REQUIRE(km->getValue(1.1) == "foo");
    REQUIRE(km->getValue(22.2) == "bar");
    REQUIRE(km->getValue(333.3) == "baz");
    REQUIRE(km->getLength() == 3);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->removePair(1.1);
    REQUIRE(km->getValue(22.2) == "bar");
    REQUIRE(km->getValue(333.3) == "baz");
    REQUIRE(km->getLength() == 2);
    REQUIRE(km->getCapacity() >= km->getLength());

    km->reset();
    REQUIRE(km->getCapacity() == 1);
    REQUIRE(km->getLength() == 0);
    REQUIRE(km->isEmpty());
};