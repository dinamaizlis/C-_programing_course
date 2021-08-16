#include <string>
#include <map>
#include <iostream>
#include <bits/stdc++.h>

namespace ariel{

class NumberWithUnits {
   static std::map< std::string ,std::map<std::string,double>> unit_map; 
public:
   	
//static std::map< std::string ,std::map<std::string,double>> unit_map; 
	double unit_size;
	std::string unit_name;

NumberWithUnits (const double& unit_size1=0.0,const std::string& unit_name1=" "){
	unit_size=unit_size1;
	unit_name=unit_name1;
}
static double convert(std::string src, std::string dest, double size){
	//cout<<"map.size()"<<unit_map.size()<<endl;
	std::string the_dest=dest;
	std::string the_src=src;
	std::string temp="";
	std::string find=src;
	double sum=size;
	int flag=0;
	try{
	// std::cout<< "src " <<src<<std::endl;
	// std::cout<< "dest " <<dest<<std::endl;
	// std::cout<< "temp " <<temp<<std::endl;
	// std::cout<< "sum " <<sum<<std::endl;
	while(temp!=dest && flag<unit_map.size()){ ////
		for(auto const &it :unit_map) {
			if((it.first)==(find)){
				//std::cout<< "if1.first" <<it.first<<std::endl;
 				for(auto const &if2 : it.second) {
					temp=if2.first;
					find=if2.first;
					//std::cout<< "if2.first" <<if2.first<<std::endl;
					//cout<< "if2.second   " <<if2.second<<endl;
					sum=sum*(if2.second);
					//cout<< "sum1 " <<sum<<endl;
					//cout<<temp<<endl;
					if(temp==dest){
						//cout<< "sum the" <<sum<<endl;
						return sum;
					}
				//it=map.end();
				}
			}
		}
		flag++;
	}
	flag=0;
	//std::cout<< "src " <<src<<std::endl;
	if(temp==""){
		//std::cout<< "dest- empty"<<dest<<std::endl;
		//temp=the_src;//dest;
		dest=the_src;
	//	std::cout<< "ssss"<<std::endl;

	}
	else{
	dest=the_dest;	
	}
	//std::string temp1=src;
	src=temp;
	//dest=the_dest;//temp1;//dest
	find=the_dest;//src
	
	// std::cout<< "src " <<src<<std::endl;
	// std::cout<< "dest " <<dest<<std::endl;
	// std::cout<< "temp " <<temp<<std::endl;
	// std::cout<< "sum " <<sum<<std::endl;
	// std::cout<< "find  " <<find<<std::endl;
	while(temp!=dest && flag<unit_map.size()){
		//cout<< "tttttt" <<temp<<endl;
		for(auto const &it :unit_map) {
			if((it.first)==(find)){
				//std::cout<< "if1   .first" <<it.first<<std::endl;
 				for(auto const &if2 : it.second) {
					 //std::cout<< "find  " <<find<<std::endl;
					 //std::cout<< "if   .first" <<if2.first<<std::endl;
					//if((if2.first)==(find)){
					//if((it->first).compare(find)){
					temp=if2.first;
					find=if2.first;
					//std::cout<< "find  " <<find<<std::endl;
					// std::cout<< "if2.second  " <<if2.second<<std::endl;
					//cout<< "it.first   " <<it.first<<endl;
					//std::string temp=map[src][];
					sum=sum/(if2.second);
					//std::cout<<"sum   "<<sum<<std::endl;

					if(temp==dest){
						//std::cout<< "sum :" <<sum<<std::endl;
						return sum;
					}
				}
			}
			
		}
		flag++;
	}
	
	}
	catch(std::string mess){ 
		std::cout<<"Units do not match - ["<<the_src<<"] cannot be converted to ["<< the_dest<<"]"<<std::endl;
	}
return sum;
}
	 //const NumberWithUnits operator+(const NumberWithUnits & other)const;
	NumberWithUnits& operator+=(const NumberWithUnits & other){
		double afterconvert=convert(other.unit_name,unit_name,other.unit_size);
		unit_size=unit_size+afterconvert;
		return *this;
	}
	const NumberWithUnits operator+()const{
		return NumberWithUnits(unit_size,unit_name);
	}
	friend NumberWithUnits operator+(const NumberWithUnits & other1,const NumberWithUnits & other2);
	

	const NumberWithUnits operator-()const{
		return NumberWithUnits(-unit_size,unit_name);
	}
	NumberWithUnits& operator-=(const NumberWithUnits & other){
		double afterconvert=convert(other.unit_name,unit_name,other.unit_size);
		unit_size=unit_size-afterconvert;
		return *this;
	}
	friend NumberWithUnits operator-(const NumberWithUnits& other1,const NumberWithUnits& other2);
	 
        
    friend bool operator>(const NumberWithUnits& other1,const NumberWithUnits& other2);  
    friend bool operator>=(const NumberWithUnits& other1,const NumberWithUnits& other2);
    friend bool operator<(const NumberWithUnits& other1,const NumberWithUnits& other2);  
    friend bool operator<=(const NumberWithUnits& other1,const NumberWithUnits& other2);  
    friend bool operator==(const NumberWithUnits& other1,const NumberWithUnits& other2);  
    friend bool operator!=(const NumberWithUnits& other1,const NumberWithUnits& other2);  
       
    NumberWithUnits& operator++(){
		unit_size++;
		return *this;
	}
    const NumberWithUnits operator++(int dummy){
		NumberWithUnits copy=*this;
		unit_size++;
		return copy;
	} 
       
       
    NumberWithUnits& operator--(){
		unit_size--;
		return *this;
	}
    const NumberWithUnits operator--(int dummy){
		NumberWithUnits copy=*this;
		unit_size--;
		return copy;
	}
       
    friend NumberWithUnits operator*(const double dummy,const NumberWithUnits & other);
	//friend const NumberWithUnits operator*(const NumberWithUnits & other,const double dummy);
       
    friend std::ostream& operator<< (std::ostream& os,const NumberWithUnits& c);
    friend std::istream& operator>> (std::istream& input, NumberWithUnits& c);
    static void read_units(std::ifstream& units_file);
	static void print();
};

};
