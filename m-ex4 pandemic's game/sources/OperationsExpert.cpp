
#include <iostream>
#include <string>
#include <map>
#include"Player.hpp"
#include"City.hpp"
#include"Board.hpp"
#include"OperationsExpert.hpp"


namespace pandemic {

     OperationsExpert& OperationsExpert::build(){
          board.city_map.at(position).build_research_station();
          return *this;
     }
     std::string OperationsExpert::role(){
          return "OperationsExpert";
     }
    
};