
#include <iostream>
#include <string>
#include <map>
#include"Player.hpp"
#include"Dispatcher.hpp"


namespace pandemic {    
    Dispatcher& Dispatcher::fly_direct(const City& c){
        if(board.city_map.at(position).has_research_station()){
            position=c;
            return *this;
        }
        else{
              for(auto i : cards){
               if(i==c){
                    position=c;
                    cards.erase(c);
                    board.all_cards.insert(c);
                    return *this;
               }
          }
        }
          throw invalid_argument("illegal- there isnt the city card");
          return *this;
     }
      std::string Dispatcher::role(){
          return "Dispatcher";
      }

};