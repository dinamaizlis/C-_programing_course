
#include <iostream>
#include <string>
#include <map>
#include"Player.hpp"
#include"Virologist.hpp"

namespace pandemic {

    Virologist&  Virologist::treat(const City& c){
        if(c==position){
            if(board.city_map.at(c).get_level_disese()==0){
                    throw invalid_argument("illegal- the level_disese=0 "); 
                }
            for(auto i:board.madicent){
                    if(i==board.city_map.at(c).color){
                            board.city_map.at(c).set_level_disese(0);
                            return *this;
                    }
                }
                int level=board.city_map.at(c).get_level_disese();
                board.city_map.at(c).set_level_disese(level-1); 
                return *this;    
        }
        for (auto i : cards){
            if(i==c){
                if(board.city_map.at(c).get_level_disese()==0){
                    throw invalid_argument("illegal- the level_disese=0 "); 
                }
                for(auto i:board.madicent){
                    if(i==board.city_map.at(c).color){
                            board.city_map.at(c).set_level_disese(0);
                            cards.erase(c);
                            //cout<<"g"<<endl;
                            return *this;
                    }
                }
                //cout<<"f"<<endl;
                int level=board.city_map.at(c).get_level_disese();
                board.city_map.at(c).set_level_disese(level-1);
                cards.erase(c);  
                return *this;
            }
           
        }
        
           throw invalid_argument("illegal-there isnt card");
           
    return *this;
    }
    std::string Virologist::role(){
        return "Virologist";
    }
}