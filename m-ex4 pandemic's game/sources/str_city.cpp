
#ifndef STR_CITY_H
#define STR_CITY_H
#include <vector>
#include "Color.hpp"
#include "City.hpp"
#include <iostream>
#include <string>
//private:
class str_city{
public:
    pandemic::Color color;
    std::vector<pandemic::City> neighbors;    
    int level_disese;
    //drugs_discoered= ?
    bool research_station;

str_city(pandemic::Color c,std::vector<pandemic::City>n): color(c),neighbors(n),level_disese(0),research_station(false){}
//str_city(){};

//function


bool has_research_station(){
    return research_station;
}
void build_research_station(){
    research_station=true;
}
void remove_research_station(){
    research_station=false;
}
int & get_level_disese(){
    return level_disese;
}
void set_level_disese(int n){
    level_disese=n;
}
// int &get_Color(){

//     return pandemic::color;
// }

};


#endif
