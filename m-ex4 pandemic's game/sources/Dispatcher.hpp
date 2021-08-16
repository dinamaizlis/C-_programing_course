#pragma once
#include "Player.hpp"


namespace pandemic {
  class Dispatcher : public Player{
    public:
      Dispatcher(Board& b, City c):Player(b,c){}
      //virtual 
      Dispatcher& fly_direct(const City& c);
      std::string role();
  };
};