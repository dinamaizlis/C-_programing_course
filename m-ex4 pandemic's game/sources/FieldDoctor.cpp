
#include <iostream>
#include <string>
#include <map>
#include"Player.hpp"
#include"FieldDoctor.hpp"

namespace pandemic {
    FieldDoctor& FieldDoctor::treat(const City &c){
        // vector<City> n= board.city_map.at(position).neighbors;
        // for(auto j : n){
        //     if(j==c){
                if(board.city_map.at(c).get_level_disese()==0){
                    throw invalid_argument("illegal- the level_disese=0 "); 
                }
                vector<City> neg=board.city_map.at(position).neighbors;
                if(c!=position&&(count(neg.begin(),neg.end(),c)==0)){
                    throw invalid_argument("illegal- not neigbor "); 
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
   

    std::string FieldDoctor::role(){
        return "FieldDoctor";
    }
};