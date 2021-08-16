#pragma once
#include "Player.hpp"
#include"Board.hpp"

namespace pandemic {
    class Medic : public Player{
        public:
            Medic(Board& board, City c):Player(board,c){}
           Player& drive(const City& c);
           Player& fly_direct(const City& c);
           Player& fly_charter(const City& c);
           Player& fly_shuttle(const City& c);
           Medic& treat(const City &c);
            std::string role();
    };
}