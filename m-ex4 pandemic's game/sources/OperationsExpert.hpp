#pragma once
#include "Player.hpp"


namespace pandemic {
    class OperationsExpert: public Player{
        public:
            OperationsExpert(Board& b, City c):Player(b,c){}
            //virtual 
            OperationsExpert& build();
            std::string role();
    };
};
