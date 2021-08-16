#pragma once
#include "Player.hpp"


namespace pandemic {
  class Scientist : public Player{
    private:
    int min_card;
      public:
        Scientist(Board& b, City c,int min_card):Player(b,c),min_card(min_card){}
        std::string role();
        //virtual 
        Scientist& discover_cure(const Color& c);
  };
};