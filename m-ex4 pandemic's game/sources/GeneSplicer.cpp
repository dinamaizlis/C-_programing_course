
#include <iostream>
#include <string>
#include <map>
#include"Player.hpp"
#include"GeneSplicer.hpp"

namespace pandemic {
    GeneSplicer& GeneSplicer::discover_cure(const Color& c){
         
	        if (count(board.madicent.begin(),board.madicent.end(),c)!=0){
	            return *this;
	        }
	     //    if(board.city_map.at(position).has_research_station()!=0){
          //      throw invalid_argument("illegal- tha position doesnt have research station"); 
          //      return *this; 
          // }
          int counter=0;
          std::set<City>to_erase; // a set that sing the city with the color c / the size need to be 5
          for(auto i: cards){
               if(counter<=5){
                    //if(board.city_map.at(i).color==c){
                         counter=counter+1;
                         to_erase.insert(i);
                         
                    //}
               }
          }
          if(counter<5){
               throw invalid_argument("illegal- there isnt enough cards"); 
               return *this;
          }
          if(counter>=5){
               for(auto i: to_erase){ //delet 5 cardes with the same color by the ser to_erase
                    cards.erase(i);
                    board.all_cards.insert(i);
               }
               board.madicent.insert(c);
          }     
     return *this;  
     }
     //    if(board.madicent.find(c)!=board.madicent.end()){
     //           if(board.city_map.at(position).has_research_station()){
     //                int counter=0;
     //                std::set<City>to_erase;
     //                for(auto i: cards){
     //                     if(counter<5){
     //                               to_erase.insert(i);
                              
     //                     }
     //                }
     //                if(counter>=5){
     //                     for(auto i: to_erase){ //delet 5 cardes with the same color by the ser to_erase
     //                          cards.erase(i);
     //                          board.all_cards.insert(i);
     //                     }
     //                     board.madicent.insert(c);
     //                }
     //           }
     //           else{
     //                throw invalid_argument("illegal- there isnt enough cards"); 
     //           }
               
     //      }
     // return *this;
     // }
    
    std::string GeneSplicer::role(){
        return "GeneSplicer";
    }

}