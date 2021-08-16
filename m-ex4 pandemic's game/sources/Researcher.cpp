
#include <iostream>
#include <string>
#include <map>
#include <set>
#include"Player.hpp"
#include"Researcher.hpp"

int numofcard=5;
namespace pandemic {
     Researcher & Researcher::discover_cure(const Color& c){

            if (count(board.madicent.begin(),board.madicent.end(),c)!=0){
	            return *this;
	        }
	    //     if(!board.city_map.at(position).has_research_station()){
        //        throw invalid_argument("illegal- tha position doesnt have research station"); 
        //        return *this; 
        //   }
          int counter=0;
          std::set<City>to_erase; // a set that sing the city with the color c / the size need to be 5
          for(auto i: cards){
               if(counter<numofcard){
                    if(board.city_map.at(i).color==c){
                         counter=counter+1;
                         to_erase.insert(i);
                         
                    }
               }
          }
          if(counter<numofcard){
               throw invalid_argument("illegal- there isnt enough cards"); 
               return *this;
          }
          if(counter>=numofcard){
               for(auto i: to_erase){ //delet 5 cardes with the same color by the ser to_erase
                    cards.erase(i);
                    board.all_cards.insert(i);
               }
               board.madicent.insert(c);
          }     
     return *this;  
     }
    // Researcher & Researcher::discover_cure(const Color& c){
    //    if(cards.size()<5){
    //             throw invalid_argument("illegal- there isnt enough cards");  
    //         }
            

    //     //if(board.madicent.find(c)!=board.madicent.end()){ //if there is cure
    //         int counter=0;
    //         std::set<City>to_erase;
    //         cout<<"t"<<endl;
    //         for(auto i: cards){
    //             if(counter<=5){
    //                 if(board.city_map.at(i).color==c){
    //                     counter=counter+1;
    //                     to_erase.insert(i);
    //                 }
    //             }
    //         }
    //         cout<<"F"<<endl;
    //         if(counter>=5){
                
    //             for(auto i: to_erase){ //delet 5 cardes with the same color by the ser to_erase
    //                 cards.erase(i);
    //                 board.all_cards.insert(i);
    //             }
                
    //             board.madicent.insert(c);
    //             return *this;
    //        // } 
    //         //else{
    //         throw invalid_argument("illegal- there isnt enough cards");   
    //         //}                     
    //     }
    //     return *this;
    // }

    std::string Researcher::role(){
        return "Researcher";
    }
}