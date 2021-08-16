
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include"Player.hpp"
#include"Medic.hpp"

//#include"Board.hpp"

namespace pandemic {
    Player& Medic::drive(const City& c){

        if (board.madicent.count(board.city_map.at(c).color) !=0){
        //std::cout<<"ggg"<<std::endl;
	           Medic::treat(c);
        }
        Player::drive(c);
        return *this;

     }

     
     Player& Medic::fly_direct(const City& c){
        if (board.madicent.count(board.city_map.at(c).color) !=0){
	           Medic::treat(c);
        } 
        Player::fly_direct(c);
        return *this;
     }
Player& Medic::fly_charter(const City& c){
      if (board.madicent.count(board.city_map.at(c).color) !=0){
	           Medic::treat(c);
        } 
        Player::fly_charter(c);
        return *this;    
     }


//good
     Player& Medic::fly_shuttle(const City& c){
           if (board.madicent.count(board.city_map.at(c).color) !=0){
	            Medic::treat(c);
        } 
          Player::fly_shuttle(c);
          return *this;
     }
    Medic& Medic::treat(const City &c){
        
        std::cout<<"level_disese   "<<board.city_map.at(c).level_disese<<std::endl;
        //   if(c!=position){
        //        throw invalid_argument("illegal- the city != position "); 
        //   }
          if(board.city_map.at(c).level_disese==0){
               throw invalid_argument("illegal- the city != position "); 
          }
          board.city_map.at(c).set_level_disese(0);
     return *this;
    }

    std::string Medic::role(){
        return "Medic";
    }
}