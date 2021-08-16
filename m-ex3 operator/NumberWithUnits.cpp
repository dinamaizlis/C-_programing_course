
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "NumberWithUnits.hpp"
const double epsilon=0.01;

namespace ariel{
std::map< std::string ,std::map<std::string,double>> NumberWithUnits::unit_map;
void NumberWithUnits::print(){	
	for(auto const &ent1 :unit_map) {
			cout << " first key " << ent1.first << endl;
 		for(auto const &ent2 : ent1.second) {
    		//ent2.first is the second key
    		//ent2.second is the data
			cout << "second key " << ent2.first << " " << ent2.second <<  endl;
		}
	}
}

void NumberWithUnits::read_units(std::ifstream&  units_file){
	
	std::string line;

		while(getline(units_file,line)){
			stringstream g(line);
			int one=0;
			std::string sourc;
			std::string equel;
			std::string dest;
			double number = NAN;
			g>>one>>sourc>>equel>>number>>dest; 
			std::map<std::string,double>new_map;
			new_map[dest]=number;
			unit_map[sourc]=new_map;
		}
}


NumberWithUnits operator*(const double dummy,const NumberWithUnits & other){
		   return NumberWithUnits(dummy*other.unit_size,other.unit_name);
 }
// const NumberWithUnits operator*(const NumberWithUnits & other,const double dummy){
// 		   return NumberWithUnits(dummy*other.size,other.unit_name);
//  } 
NumberWithUnits operator-(const NumberWithUnits & other1,const NumberWithUnits& other2){
	double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
	//cout<<"afterconvert "<<afterconvert<<endl;
	return NumberWithUnits(other1.unit_size-afterconvert,other1.unit_name);
	}
	
NumberWithUnits operator+(const NumberWithUnits & other1,const NumberWithUnits & other2){
		 double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
		 return NumberWithUnits(other1.unit_size+afterconvert,other1.unit_name);
}
bool operator>(const NumberWithUnits& other1,const NumberWithUnits& other2){
	double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
	if(afterconvert<other1.unit_size){
		return true;
	}
	return false;
}
bool operator>=(const NumberWithUnits& other1,const NumberWithUnits& other2){
	double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
	if(other1.unit_size>=afterconvert){
		return true;
	}
	return false;
}
bool operator<(const NumberWithUnits& other1,const NumberWithUnits& other2){
	double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
	if(afterconvert>other1.unit_size){
		return true;
	}
	return false;
}
bool operator<=(const NumberWithUnits& other1,const NumberWithUnits& other2){
	double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
	if(afterconvert>=other1.unit_size){
		return true;
	}
	return false;
}
bool operator==(const NumberWithUnits& other1,const NumberWithUnits& other2){
	if(other1.unit_name==other2.unit_name){
		if(other1.unit_size-other2.unit_size <epsilon &&other1.unit_size-other2.unit_size >-epsilon){
			return true;
		}
		
			return false;
		
	}
	double afterconvert=ariel::NumberWithUnits::convert(other2.unit_name,other1.unit_name,other2.unit_size);
	if(other1.unit_size-afterconvert<epsilon &&other1.unit_size-afterconvert>-epsilon){
	 	return true;
	 }
	  return false;
}

bool operator!=(const NumberWithUnits& other1,const NumberWithUnits& other2){
	if(other1==other2){
		return false;
	}
	return true;
}
ostream& operator<<(ostream& os, const NumberWithUnits& c) {
    return (os << c.unit_size << '[' << c.unit_name << ']');
}
static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar=0;
    input >> actualChar;
    if (!input){
     return input;
    }

    if (actualChar!=expectedChar) {
        // failbit is for format error
        input.setstate(ios::failbit);
    }
    return input;
}

istream& operator>>(istream& input, NumberWithUnits& c) {
    double new_size=0.0;
	string new_unit_name;
    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();
    if ( (!(input >> new_size))                 ||
         (!getAndCheckNextCharIs(input,'['))  ||
         (!(input >> new_unit_name))                 ||
         (!(getAndCheckNextCharIs(input,']'))) ) {
        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } else {
        c.unit_size = new_size;
        c.unit_name = new_unit_name;
    }
    return input;
}



};

