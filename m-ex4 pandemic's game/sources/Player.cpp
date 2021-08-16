
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include"City.hpp"
#include"Color.hpp"
#include"Board.hpp"
#include"Player.hpp"


namespace pandemic {
    
     //good   
     Player& Player::drive(const City& c){
          vector<City> city_neighbors= board.city_map.at(position).neighbors; // get the neighbors
          for(auto i :city_neighbors){
               if(i ==c){
                    position=c;
                    return *this;
               }
          }
          throw invalid_argument("illegal- cities are not neighboring");
          return *this;
     }

     //good
     Player& Player::fly_direct(const City& c){
          for(auto i : cards){ //check if there is the city card from the cards in hand
               if(i==c){
                    position=c; 
                    cards.erase(c); //delet from cards
                    board.all_cards.insert(c); //add
                    return *this;
               }
          }
          throw invalid_argument("illegal- there is not card from `cards`that represet the city");
          return *this;
     }

     //good
     Player& Player::fly_charter(const City& c){
          for(auto i : cards){
               if(i==position){//the card that represet the position
                    cards.erase(position);
                    board.all_cards.insert(position);
                    position=c;
                    return *this;
               }
          }
          throw invalid_argument("illegal- there is not card from `cards`that represet the ");
          return *this;
     }


//good
     Player& Player::fly_shuttle(const City& c){
          if(position==c){// if the city that wont to move is the position
            throw invalid_argument("illegal- cannot fly from city to it self");
          }
          if(board.city_map.at(position).has_research_station()){ //if there is research station 
               if(board.city_map.at(c).has_research_station()){ // if city c had research station 
                    position=c;
                    return *this;
               }
          }
          throw invalid_argument("illegal- the city c doesnt have a research station");
          return *this;
     }
 //   good 
     Player& Player::build(){
          if(board.city_map.at(position).has_research_station()){ //if there is research station dont do nothing
               return *this;
          }
          for(auto i :cards){//pass over the cards
               if(i==position){
                    board.city_map.at(position).build_research_station();//build
                    cards.erase(position);// delet card
                    board.all_cards.insert(position);//add
                    return *this;
               }
          }
          throw invalid_argument("illegal- there is not card from `cards`that represet the position");
     return *this;
     }

//
Player& Player::discover_cure(const Color& c) {
     //cout<<"ffff"<<endl;
	        if (count(board.madicent.begin(),board.madicent.end(),c)!=0){
	            return *this;
	        }
	        if(!board.city_map.at(position).has_research_station()){
               throw invalid_argument("illegal- tha position doesnt have research station"); 
               return *this; 
          }
          int counter=0;
          std::set<City>to_erase; // a set that sing the city with the color c / the size need to be 5
          for(auto i: cards){
               if(counter<5){
                    if(board.city_map.at(i).color==c){
                         counter=counter+1;
                         to_erase.insert(i);
                         
                    }
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
	//         if (board.city_map.at(position).has_research_station())
	//         {
	//             int counter = 0;
	//             for (const auto& it : cards) 
	//             {
	//                 if (board.city_map.at(it).color == color)
	//                 {
	//                     counter++;
	//                 }
	//             }
	//             if (counter >= min_to_dis)
	//             {
	//                 board.madicent.insert(color);
	
	//                 //removing 5 cards
	//                 counter = 0;
	               
	//                 for (auto i = cards.begin(); i != cards.end() && counter < min_to_dis; ++i)
	//                 {
	//                     if (board.city_map.at(*i).color == color)
	//                     {
	//                         cards.erase(i++);
	//                         counter++;
	//                     }
	//                 }
	//             }
	//             else
	//             {
	//                 throw invalid_argument("Illegal action: you don't have enough cards to discover a cure");
	//             }
	//         }
	//         else
	//         {
	//             throw invalid_argument("Illegal action: Your location doesn't have a research station");
	//         }
	        
	//         return *this;
	//     }
    // Player& Player::discover_cure(const Color& c){
     //      if(board.madicent.find(c)==board.madicent.end()){
     //        return *this;   
     //      }
     //      if(!board.city_map.at(position).has_research_station()){
     //           throw invalid_argument("illegal- tha position doesnt have research station"); 
     //           return *this; 
     //      }
     //      int counter=0;
     //      std::set<City>to_erase; // a set that sing the city with the color c / the size need to be 5
     //      for(auto i: cards){
     //           if(counter<5){
     //                if(board.city_map.at(i).color==c){
     //                     counter=counter+1;
     //                     to_erase.insert(i);
                         
     //                }
     //           }
     //      }
     //      if(counter<5){
     //           throw invalid_argument("illegal- there isnt enough cards"); 
     //           return *this;
     //      }
     //      if(counter>=5){
     //           for(auto i: to_erase){ //delet 5 cardes with the same color by the ser to_erase
     //                cards.erase(i);
     //                board.all_cards.insert(i);
     //           }
     //           board.madicent.insert(c);
     //      }     
     // return *this;  
     // }
          //if(board.madicent.find(c)!=board.madicent.end()){// if the madicent doesnt have the color c 
               //if(board.city_map.at(position).has_research_station()){//if there is 
                    // int counter=0;
                    // std::set<City>to_erase;
                    // for(auto i: cards){
                    //      if(counter<5){
                    //           if(board.city_map.at(i).color==c){
                    //                counter=counter+1;
                    //                to_erase.insert(i);
                    //           }
                    //      }
                    // }
                    // if(counter>=5){
                    //      for(auto i: to_erase){ //delet 5 cardes with the same color by the ser to_erase
                    //           cards.erase(i);
                    //           board.all_cards.insert(i);
                    //      }
                    //      board.madicent.insert(c);
                    //      return *this;
                    // }
                    // throw invalid_argument("illegal- there isnt enough cards"); 
              // }
          //}
               //else{
                //   throw invalid_argument("illegal- tha position doesnt have research station"); 
              // }
               
          
     // return *this;
     // }
     Player& Player::treat(const City& c){
          std::cout<<"level_disese   "<<board.city_map.at(c).level_disese<<std::endl;
          if(c!=position){
               throw invalid_argument("illegal- the city != position "); 
          }
          //if(board.city_map.at(position).get_level_disese()==0){
               if(board[c]==0){
               throw invalid_argument("illegal- the level_disese=0 "); 
          }
          for(auto i:board.madicent){
               if(i==board.city_map.at(position).color){
                    board.city_map.at(position).set_level_disese(0);
                    return *this;
               }
          }
          int level=board.city_map.at(position).get_level_disese();
          board.city_map.at(position).set_level_disese(level-1);
     return *this;
     }
     
     string Player::role(){
     return "";
     }
     Player& Player::take_card(const City& c){
          cards.insert(c);
     return *this;
     }
     void Player::remove_cards(){
          for(auto i :cards){
               cards.erase(i);
               board.all_cards.insert(i);
          }
     }
   
};


