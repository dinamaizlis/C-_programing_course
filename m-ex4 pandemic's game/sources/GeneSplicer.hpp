#pragma once
#include "Player.hpp"


namespace pandemic {
    class GeneSplicer : public Player{
        public:
            GeneSplicer (Board& b, City c):Player(b,c){}
            //virtual 
            GeneSplicer& discover_cure(const Color& c);
            std::string role();
    };
};