/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */
#include <random>
#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code") {

    //CHECK(nospaces(snowman(11114411)) == nospaces(" _===_ \n (.,.) \n ( : ) \n ( : ) "));- example test
    //hat check
    CHECK(nospaces(snowman(11114411)) == nospaces(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(21114411)) == nospaces("  ___  \n ..... \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(31114411)) == nospaces("   _   \n  /_\\  \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(41114411)) == nospaces("  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) "));
    //nose/maouth check
    CHECK(nospaces(snowman(11114411)) == nospaces(" _===_ \n (.,.) \n ( : ) \n ( : ) "));	
    CHECK(nospaces(snowman(12114411)) == nospaces(" _===_ \n (...) \n ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(13114411)) == nospaces(" _===_ \n (._.) \n  ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(14114411)) == nospaces(" _===_ \n (. .) \n  ( : ) \n ( : ) "));
    //eyes check
    CHECK(nospaces(snowman(11114411)) == nospaces(" _===_ \n (.,.) \n ( : ) \n ( : ) "));	
    CHECK(nospaces(snowman(12224411)) == nospaces(" _===_ \n (o.o) \n  ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(12334411)) == nospaces(" _===_ \n (O.O) \n  ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(12444411)) == nospaces(" _===_ \n (-.-) \n  ( : ) \n ( : ) "));
    // armes check	
    CHECK(nospaces(snowman(12111111)) == nospaces(" _===_ \n (...) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(12112211)) == nospaces(" _===_ \n\\(...)/\n ( : ) \n ( : ) "));
    CHECK(nospaces(snowman(12113311)) == nospaces(" _===_ \n (...) \n/( : )\\\n ( : ) "));
    CHECK(nospaces(snowman(11114411)) == nospaces(" _===_ \n (.,.) \n ( : ) \n ( : ) "));	
    //torso+base check
    CHECK(nospaces(snowman(11114411)) == nospaces(" _===_ \n (.,.) \n ( : ) \n ( : ) "));		
    CHECK(nospaces(snowman(12114422)) == nospaces(" _===_ \n (...) \n (] [) \n (\" \")") );
    CHECK(nospaces(snowman(12114433)) == nospaces(" _===_ \n (...) \n  (> <) \n (___) "));
    CHECK(nospaces(snowman(12114444)) == nospaces(" _===_ \n (...) \n  (   ) \n (   ) "));
    
    
    //more tests
    CHECK(nospaces(snowman(32443333)) == nospaces("   _   \n  /_\\  \n (-.-) \n/(> <)\\\n (___) \n"));
    CHECK(nospaces(snowman(44444432)) == nospaces("  ___  \n (_*_) \n (- -) \n (> <) \n (\" \") "));
    CHECK(nospaces(snowman(33232124)) == nospaces("   _   \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) "));
    CHECK(nospaces(snowman(44242123)) == nospaces("  ___  \n (_*_) \n\\(o -) \n (] [)>\n (___) "));
    CHECK(nospaces(snowman(41341144)) == nospaces("  ___  \n (_*_) \n (O,-) \n<(   )>\n (   ) "));
    CHECK(nospaces(snowman(11111111)) == nospaces(" _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(22222222)) == nospaces("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(33333333)) == nospaces("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) "));
    CHECK(nospaces(snowman(44444444)) == nospaces("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
    CHECK(nospaces(snowman(12333321)) == nospaces(" _===_ \n (O.O) \n/(] [)\\\n ( : ) "));
    CHECK(nospaces(snowman(23232223)) == nospaces("  ___  \n ..... \n\\(o_O)/\n (] [) \n (___) "));
    CHECK(nospaces(snowman(11112311)) == nospaces(" _===_ \n\\(.,.)\n  ( : )\\\n ( : ) "));
    CHECK(nospaces(snowman(44114432)) == nospaces("  ___  \n (_*_) \n (. .) \n (><) \n (\" \") "));
    CHECK(nospaces(snowman(44114432)) == nospaces("  ___  \n (_*_) \n (. .) \n (> <) \n (\" \")"));
    
    

}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(rand()%10000000));//7 digit
    CHECK_THROWS(snowman(rand()%1000000));
    CHECK_THROWS(snowman(rand()%100000));
    CHECK_THROWS(snowman(rand()%10000));
    CHECK_THROWS(snowman(rand()%1000));
    CHECK_THROWS(snowman(rand()%100));
    CHECK_THROWS(snowman(rand()%10));
    CHECK_THROWS(snowman(rand()%1000000000));//9 digit
    int randnum=rand();
    if((randnum/8)!=1) CHECK_THROWS(snowman(randnum)); // there are digits<8 ||8<digits 
    //if there are 8 digits and [1,8] digits are not 1/2/3/4
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(15222324));
    CHECK_THROWS(snowman(12272324));
    CHECK_THROWS(snowman(12270324));
}
