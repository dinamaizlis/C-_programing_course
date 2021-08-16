
#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <random>

using namespace std;
namespace ariel{
TEST_CASE("test1"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{3.1 ,"km"};
    NumberWithUnits b{25000 ,"cm"}; 
    // NumberWithUnits mal11= b*2;
    //     CHECK(mal11=NumberWithUnits{ 50000, "cm"});
    // NumberWithUnits mal= 2*b;
        //CHECK(mal==NumberWithUnits{ 50000, "cm"});
    NumberWithUnits una= -b;
        CHECK(una==NumberWithUnits{ -25000, "cm"});
    NumberWithUnits unaa= -a;
        CHECK(unaa==NumberWithUnits{ -3.1 ,"km"});                 
    NumberWithUnits sum11=a+b;
        CHECK(sum11==NumberWithUnits{3.35 , "km"});
    NumberWithUnits sum=b+a;
        CHECK(sum==NumberWithUnits{335000 , "cm"});    
    NumberWithUnits min11=a-b;
        CHECK(min11==NumberWithUnits{2.85 , "km"});   
    NumberWithUnits min=b-a;
        CHECK(min==NumberWithUnits{-285000 , "cm"});
    CHECK(a>b);    
    CHECK(a>=b);
    CHECK(a!=b);    
    CHECK(b<a);
    CHECK(b<=a);

    NumberWithUnits c{3.1 ,"km"};
    CHECK(c==a);
    CHECK(c<=a);
    CHECK(c>=a);
}
TEST_CASE("test- hour to sec"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{4.1 ,"hour"};
    NumberWithUnits b{2880.0 ,"sec"}; 
    // NumberWithUnits mal12= b*2;
    //     CHECK(mal12=NumberWithUnits{ 5760.0, "sec"});
    // NumberWithUnits mal22= 2*b;
     //  CHECK(mal22=NumberWithUnits{ 5760.0, "sec"}); 
    NumberWithUnits una= -b;
        CHECK(una==NumberWithUnits{ -2880.0 ,"sec"});
    NumberWithUnits unaa= -a;
        CHECK(unaa==NumberWithUnits{ -4.1 ,"hour"});        
    NumberWithUnits sum12=a+b;
        CHECK(sum12==NumberWithUnits{ 4.9, "hour"});
    NumberWithUnits sum22=b+a;
        CHECK(sum22==NumberWithUnits{17640 , "sec"});    
    NumberWithUnits min12=a-b;
        CHECK(min12==NumberWithUnits{3.3 , "hour"});   
    NumberWithUnits min22=b-a;
        CHECK(min22==NumberWithUnits{-11880, "sec"});
    CHECK(a>b);    
    CHECK(a>=b);
    CHECK(a!=b);    
    CHECK(b<a);
    CHECK(b<=a);

    NumberWithUnits c{2880.0 ,"sec"};
    CHECK(c==b);
    CHECK(c<=b);
    CHECK(c>=b);

}

};

