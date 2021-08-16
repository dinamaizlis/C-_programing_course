#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include"City.hpp"
#include"Color.hpp"
#include"str_city.cpp"
#include <set>
namespace pandemic {

    class Board{
        
    public:
    std::set<Color>madicent; //by color - represent the madicent that had on the board
    std::set<City>all_cards; // represent the 48 cards in the begin
    map<pandemic::City, str_city> city_map; // map that represent key-city value- class of str_city
    Board(){
        init();//function in cpp
    }
    Board(City &c);
    void init();    
    int&  operator [] (City c);
    friend std::ostream &operator << (std::ostream&, const Board&);
    bool  is_clean();
    void  remove_cures();
    void remove_station();
    };
};



