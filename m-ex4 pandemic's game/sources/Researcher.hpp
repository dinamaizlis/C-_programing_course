#pragma once
#include "Player.hpp"


namespace pandemic {
    class Researcher : public Player{
        public:
            Researcher (Board& b, City c):Player::Player(b,c){}
            //virtual ?
            Researcher & discover_cure(const Color& c);
            std::string role();
    };
}