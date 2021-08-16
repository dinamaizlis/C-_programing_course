#include "doctest.h"
#include "Board.hpp"
#include <random>
using ariel::Direction;
using namespace ariel;
using namespace std;
Board board;

TEST_CASE("empty board"){
    CHECK(board.read(/*row=*/0,/*column*/0,Direction::Horizontal,4)=="____");
    CHECK(board.read(/*row=*/0,/*column*/0,Direction::Vertical,4)=="____");
    CHECK(board.read(/*row=*/3,/*column*/4,Direction::Horizontal,2)=="__");
    CHECK(board.read(/*row=*/1,/*column*/6,Direction::Vertical,2)=="__");
}

TEST_CASE("Horizontal Test"){
    // inserting a word
    board.post(/*row=*/1,/*column*/2,Direction::Horizontal,"hello");
    CHECK(board.read(/*row=*/1,/*column*/2,Direction::Horizontal,5)=="hello");
    CHECK(board.read(/*row=*/1,/*column*/1,Direction::Vertical,7)=="_hello_");
    //inserting a word that will create punctuation
    board.post(/*row=*/1,/*column*/7,Direction::Horizontal,"world");
    CHECK(board.read(/*row=*/3,/*column*/4,Direction::Horizontal,11)=="hello_world");

    board.post(/*row=*/1,/*column*/2,Direction::Horizontal,"dddddd");
    CHECK(board.read(/*row=*/1,/*column*/2,Direction::Horizontal,11)=="ddddddworld");
    CHECK(board.read(/*row=*/1,/*column*/1,Direction::Horizontal,13)=="_ddddddworld_");
}

TEST_CASE("Vertical Test"){
    // inserting a word
    board.post(/*row=*/1,/*column*/20,Direction::Vertical,"hello");
    CHECK(board.read(/*row=*/1,/*column*/20,Direction::Vertical,5)=="hello");
    CHECK(board.read(/*row=*/1,/*column*/19,Direction::Vertical,7)=="_hello_");
    //inserting a word that will create punctuation
    board.post(/*row=*/1,/*column*/25,Direction::Vertical,"world");
    CHECK(board.read(/*row=*/3,/*column*/20,Direction::Vertical,11)=="hello_world");
    //override
    board.post(/*row=*/1,/*column*/2,Direction::Vertical,"dddddd");
    CHECK(board.read(/*row=*/1,/*column*/20,Direction::Vertical,11)=="ddddddworld");
    CHECK(board.read(/*row=*/1,/*column*/19,Direction::Vertical,13)=="_ddddddworld_");
}

TEST_CASE("override"){
    // Vertical on Horizontal
    board.post(/*row=*/3,/*column*/1,Direction::Horizontal,"hello world");
    CHECK(board.read(/*row=*/3,/*column*/1,Direction::Horizontal,11)=="hello world");
    board.post(/*row=*/3,/*column*/2,Direction::Vertical,"hey");
    CHECK(board.read(/*row=*/3,/*column*/2,Direction::Vertical,3)=="hey");
    //-->
    CHECK(board.read(/*row=*/3,/*column*/1,Direction::Horizontal,11)=="hhllo world");

    //Horizontal on Vertical 
    board.post(/*row=*/5,/*column*/4,Direction::Vertical,"hello world");
    CHECK(board.read(/*row=*/5,/*column*/4,Direction::Vertical,11)=="hello world");
    board.post(/*row=*/6,/*column*/4,Direction::Horizontal,"hey");
    CHECK(board.read(/*row=*/6,/*column*/4,Direction::Horizontal,3)=="hey");
    //-->
    CHECK(board.read(/*row=*/5,/*column*/4,Direction::Vertical,11)=="hhllo world");
}

TEST_CASE("more tests"){

    //  on Direction::Horizontal
    board.post(7,8,Direction::Horizontal,"hello_world");  
    CHECK(board.read(7,8,Direction::Horizontal,11)=="hello_world");
    // on Direction::Vertical
    board.post(6,3,Direction::Vertical,"hello_world");  
    CHECK(board.read(6,3,Direction::Vertical,11)=="hello_world");
}
