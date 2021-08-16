#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "BinaryTree.hpp"

#include "doctest.h"
using namespace std;

using  namespace ariel;

TEST_CASE("tree_of_ints"){
BinaryTree<int> tree_of_ints;   
    CHECK_NOTHROW(tree_of_ints.add_root(4););
    CHECK_NOTHROW(tree_of_ints.add_left(4, 3););      
    CHECK_NOTHROW(tree_of_ints.add_left(3, 6););    
    CHECK_NOTHROW(tree_of_ints.add_right(6, 5););    
    CHECK_NOTHROW(tree_of_ints.add_right(4, 8););     
    CHECK_NOTHROW(tree_of_ints.add_left(8, 2););
    CHECK_THROWS(tree_of_ints.add_left(0, 2););
   
    CHECK_NOTHROW(tree_of_ints.add_left(6, 7););     
    CHECK_NOTHROW(tree_of_ints.add_left(7, 10););      
    CHECK_NOTHROW(tree_of_ints.add_right(2, 11););     
    CHECK_THROWS(tree_of_ints.add_right(9, 12););     
    CHECK_NOTHROW(tree_of_ints.add_left(2, 9);); 
 
}
TEST_CASE("tree_of_string"){
BinaryTree<string> tree_of_string;   
    CHECK_NOTHROW(tree_of_string.add_root("kovi"););
    CHECK_NOTHROW(tree_of_string.add_left("kovi", "tal"););      
    CHECK_NOTHROW(tree_of_string.add_left("tal", "ron"););    
    CHECK_NOTHROW(tree_of_string.add_right("ron", "noa"););    
    CHECK_NOTHROW(tree_of_string.add_right("kovi","michal" ););     
    CHECK_NOTHROW(tree_of_string.add_left("michal", "tamar"););
    CHECK_THROWS(tree_of_string.add_left("david", "tamar"););
    CHECK_NOTHROW(tree_of_string.add_left("ron", "shay"););     

 }


