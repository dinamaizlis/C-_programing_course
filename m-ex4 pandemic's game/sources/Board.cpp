
#include <iostream>
#include <string>
#include <map>
#include"City.hpp"
#include"Board.hpp"
#include"str_city.cpp"
using namespace std;
namespace pandemic {

 
    int&  Board::operator [] ( City c){
		//cout<<"opert[]"<<city_map.at(c).get_level_disese()<<endl;
        return city_map.at(c).get_level_disese();
    }


    bool Board::is_clean(){
        for( auto &i:city_map){
            if(i.second.get_level_disese()!=0){
                return false;
            }
        }
        return true;
    }


    void Board::remove_station(){
        for( auto &i:city_map ){
            i.second.remove_research_station();
        }
		
    }

	void  Board::remove_cures(){
		for( auto i:madicent ){
            madicent.erase(i);
		}	
    }

    // ostream& operator << (ostream &os, const Board &u){
	// return os;}
	// //represent 

    std::ostream& operator<< (std::ostream& os, const Board& u){
	        os<< "\n \033[1;31m *** Printing Board *** \033[0m \n";
	        os<< "Cures discoverd so far: ";
	        for (const auto &i : u.madicent){
	            if (i == Color::Black){
	                os << "\033[1;30mBlack \033[0m";
	            }
	            else if (i == Color::Blue){
	                os << "\033[1;34mBlue \033[0m";    
	            }
	            else if (i == Color::Red){
	                os << "\033[1;31mRed \033[0m"; 
	            }
	            else{
	                os << "\033[1;33m Yellow \033[0m"; 
	            }
	            os << " ";
	        }
			return os;
	}

void Board::init() {
	        str_city Algiers(Color::Black, vector<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo} );
	        city_map.insert({City::Algiers, Algiers});
           // all_cards.insert(Algiers);
	
	        str_city Atlanta(Color::Blue, vector<City>{City::Chicago, City::Miami, City::Washington} );
	        city_map.insert({City::Atlanta, Atlanta});
	        //all_cards.insert(Atlanta);

	        str_city Baghdad(Color::Black, vector<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi} );
	        city_map.insert({City::Baghdad, Baghdad});
            //all_cards.insert(Baghdad);
	    
	        str_city Bangkok(Color::Red, vector<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong} );
	        city_map.insert({City::Bangkok, Bangkok});
            //all_cards.insert(Bangkok);
	
	        str_city Beijing(Color::Red, vector<City>{City::Shanghai, City::Seoul} );
	        city_map.insert({City::Beijing, Beijing});
            ///all_cards.insert(Beijing);
	
	        str_city Bogota(Color::Yellow, vector<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires} );
	        city_map.insert({City::Bogota, Bogota});
            //all_cards.insert(Bogota);
	
	        str_city BuenosAires(Color::Yellow, vector<City>{City::Bogota, City::SaoPaulo} );
	        city_map.insert({City::BuenosAires, BuenosAires});
            //all_cards.insert(BuenosAires);
	
	        str_city Cairo(Color::Black, vector<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh} );
	        city_map.insert({City::Cairo, Cairo});
            //all_cards.insert(Cairo);
	
	        str_city Chennai(Color::Black, vector<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta} );
	        city_map.insert({City::Chennai, Chennai});
            //all_cards.insert(Chennai);
	
	        str_city Chicago(Color::Blue, vector<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal} );
	        city_map.insert({City::Chicago, Chicago});
            //all_cards.insert(Chicago);
	
	        str_city Delhi(Color::Black, vector<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata} );
	        city_map.insert({City::Delhi, Delhi});
            //all_cards.insert(Delhi);
	
	        str_city Essen(Color::Blue, vector<City>{City::London, City::Paris, City::Milan, City::StPetersburg} );
	        city_map.insert({City::Essen, Essen});
            //all_cards.insert(Essen);
	
	        str_city HoChiMinhCity(Color::Red, vector<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila} );
	        city_map.insert({City::HoChiMinhCity, HoChiMinhCity});
            //all_cards.insert(HoChiMinhCity);
	
	        str_city HongKong(Color::Red, vector<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei} );
	        city_map.insert({City::HongKong, HongKong});
            //all_cards.insert(HongKong);
	
	        str_city Istanbul(Color::Black, vector<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow} );
	        city_map.insert({City::Istanbul, Istanbul});
            //all_cards.insert(Istanbul);
	
	        str_city Jakarta(Color::Red, vector<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney} );
	        city_map.insert({City::Jakarta, Jakarta});
           // all_cards.insert(Jakarta);
	
	        str_city Johannesburg(Color::Yellow, vector<City>{City::Kinshasa, City::Khartoum} );
	        city_map.insert({City::Johannesburg, Johannesburg});
            //all_cards.insert(Johannesburg);
	
	        str_city Karachi(Color::Black, vector<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi} );
	        city_map.insert({City::Karachi, Karachi});
           // all_cards.insert(Karachi);
	
	        str_city Khartoum(Color::Yellow, vector<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg} );
	        city_map.insert({City::Khartoum, Khartoum});
            //all_cards.insert(Khartoum);
	
	        str_city Kinshasa(Color::Yellow, vector<City>{City::Lagos, City::Khartoum, City::Johannesburg} );
	        city_map.insert({City::Kinshasa, Kinshasa});
          //  all_cards.insert(Kinshasa);
	
	        str_city Kolkata(Color::Black, vector<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong} );
	        city_map.insert({City::Kolkata, Kolkata});
           // all_cards.insert(Kolkata);
	
	        str_city Lagos(Color::Yellow, vector<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa} );
	        city_map.insert({City::Lagos, Lagos});
           // all_cards.insert(Lagos);
	
	        str_city Lima(Color::Yellow, vector<City>{City::MexicoCity, City::Bogota, City::Santiago} );
	        city_map.insert({City::Lima, Lima});
            //all_cards.insert(Lima);
	
	        str_city London(Color::Blue, vector<City>{City::NewYork, City::Madrid, City::Essen, City::Paris} );
	        city_map.insert({City::London, London});
           // all_cards.insert(London);
	
	        str_city LosAngeles(Color::Yellow, vector<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney} );
	        city_map.insert({City::LosAngeles, LosAngeles});
           // all_cards.insert(LosAngeles);
	
	        str_city Madrid(Color::Blue, vector<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers} );
	        city_map.insert({City::Madrid, Madrid});
            //all_cards.insert(Madrid);
	
	        str_city Manila(Color::Red, vector<City>{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong} );
	        city_map.insert({City::Manila, Manila});
           // all_cards.insert(Manila);
	
	        str_city MexicoCity(Color::Yellow, vector<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota} );
	        city_map.insert({City::MexicoCity, MexicoCity});
            //all_cards.insert(MexicoCity);
	
	        str_city Miami(Color::Yellow, vector<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota} );
	        city_map.insert({City::Miami, Miami});
           // all_cards.insert(Miami);
	
	        str_city Milan(Color::Blue, vector<City>{City::Essen, City::Paris, City::Istanbul} );
	        city_map.insert({City::Milan, Milan});
           // all_cards.insert(Milan);
	
	        str_city Montreal(Color::Blue, vector<City>{City::Chicago, City::Washington, City::NewYork} );
	        city_map.insert({City::Montreal, Montreal});
           //// all_cards.insert(Montreal);
	
	        str_city Moscow(Color::Black, vector<City>{City::StPetersburg, City::Istanbul, City::Tehran} );
	        city_map.insert({City::Moscow, Moscow});
           // all_cards.insert(Moscow);
	
	        str_city Mumbai(Color::Black, vector<City>{City::Karachi, City::Delhi, City::Chennai} );
	        city_map.insert({City::Mumbai, Mumbai});
           // all_cards.insert(Mumbai);
	
	        str_city NewYork(Color::Blue, vector<City>{City::Montreal, City::Washington, City::London, City::Madrid} );
	        city_map.insert({City::NewYork, NewYork});
           // all_cards.insert(NewYork);
	
	        str_city Osaka(Color::Red, vector<City>{City::Taipei, City::Tokyo} );
	        city_map.insert({City::Osaka, Osaka});
           // all_cards.insert(Osaka);
	
	        str_city Paris(Color::Blue, vector<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London} );
	        city_map.insert({City::Paris, Paris});
            //all_cards.insert(Paris);
	
	        str_city Riyadh(Color::Black, vector<City>{City::Baghdad, City::Cairo, City::Karachi} );
	        city_map.insert({City::Riyadh, Riyadh});
            //all_cards.insert(Riyadh);
	
	        str_city SanFrancisco(Color::Blue, vector<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila} );
	        city_map.insert({City::SanFrancisco, SanFrancisco});
           // all_cards.insert(SanFrancisco);
	
	        str_city Santiago(Color::Yellow, vector<City>{City::Lima} );
	        city_map.insert({City::Santiago, Santiago});
           // all_cards.insert(Santiago);
	
	        str_city SaoPaulo(Color::Yellow, vector<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid} );
	        city_map.insert({City::SaoPaulo, SaoPaulo});
           // all_cards.insert(SaoPaulo);
	
	        str_city Seoul(Color::Red, vector<City>{City::Beijing, City::Shanghai, City::Tokyo} );
	        city_map.insert({City::Seoul, Seoul});
          //  all_cards.insert(Seoul);
	
	        str_city Shanghai(Color::Red, vector<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo} );
	        city_map.insert({City::Shanghai, Shanghai});
           // all_cards.insert(Shanghai);
	
	        str_city StPetersburg(Color::Blue, vector<City>{City::Essen, City::Istanbul, City::Moscow} );
            city_map.insert({City::StPetersburg, StPetersburg});
           // all_cards.insert(StPetersburg);
	
	        str_city Sydney(Color::Red, vector<City>{City::Jakarta, City::Manila, City::LosAngeles} );
	        city_map.insert({City::Sydney, Sydney});
            //all_cards.insert(Sydney);
	
	        str_city Taipei(Color::Red, vector<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila} );
	        city_map.insert({City::Taipei, Taipei});
           // all_cards.insert(Taipei);
	
	        str_city Tehran(Color::Black, vector<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi} );
	        city_map.insert({City::Tehran, Tehran});
           // all_cards.insert(Tehran);
	
	        str_city Tokyo(Color::Red, vector<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco} );
	        city_map.insert({City::Tokyo, Tokyo});
            //all_cards.insert(Tokyo);
	
	        str_city Washington(Color::Blue, vector<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami} );
	        city_map.insert({City::Washington, Washington});
           // all_cards.insert(Washington)
            
	    }

     
    };
