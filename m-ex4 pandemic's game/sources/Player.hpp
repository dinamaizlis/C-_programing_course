#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Player.hpp"
#include"City.hpp"
#include"Color.hpp"
#include"Board.hpp"


namespace pandemic {

  class Player{
    public:
        Board &board;
        City position;
        std::set<City> cards;
        int min_to_dis=5;
        Player(Board& b, City c):board(b),position(c){}
        //~Player();
        virtual Player& drive(const City& c);
        virtual Player& fly_direct(const City& c);
        virtual Player& fly_charter(const City& c);
        virtual Player& fly_shuttle(const City& c);
        
        virtual Player& build();
        virtual Player& discover_cure(const Color& c);
        virtual Player& treat(const City& c);
        virtual std::string role();
        virtual Player& take_card(const City& c);
        virtual void remove_cards()
        // virtual Player& remove_charter(const City& c){
        //   return *this
        // }
        // virtual Player& remove_shuttle(const City& c){
        //   return *this
        // }
        
        
        

        ;
        

        
    };
}
