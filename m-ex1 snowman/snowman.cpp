#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
#include "snowman.hpp"
const int numofdigit =8;
const int hat=0;
const int maouth=1;
const int leftarmes=4;
const int rightarmes=5;
const int torso=6;
const int base=7;
namespace ariel {


string snowman (int snow1){
string snow;    
string thesnoemen;
 
snow=snow+to_string(snow1);// convert int to string
if(snow.size()!=numofdigit){
    throw std::out_of_range{"the length of the numer is not 8 "};
}

for(int i=0;i<numofdigit;i++){
    if(snow[i]!='1'&&snow[i]!='2'&&snow[i]!='3'&&snow[i]!='4'){
        throw std::out_of_range{"the range is not between 1-4"};
    }
}
    for(int i=0; i<numofdigit;i++){
        if(i==hat){
        string toprint;
        if(snow[i]=='1'){
            toprint=" _===_ \n";
        }
        else if (snow[i]=='2') {
            toprint="  ___  \n ..... \n";
        }
        else if (snow[i]=='3') {
            toprint="   _   \n  /_\\  \n";
        }
        else{
            toprint="  ___  \n (_*_) \n";
        }
        thesnoemen=toprint;
        }
        
        if(i==maouth){
            string toprint;
            if(snow[4]=='2'){
                    toprint="\\";
                }
            toprint+="(";   
            for(int j=0;j<2;j++){
                if(snow[j+2]=='1'){
                    toprint+=".";
                }
                else if (snow[j+2]=='2') {
                    toprint+="o";
                }
                else if (snow[j+2]=='3') {
                    toprint+="O";
                }
                else{
                    toprint+="-";
                }
                if(j==0){
                   if(snow[1]=='1'){
                    toprint+=",";
                    }
                    if (snow[1]=='2') {
                        toprint+=".";
                    }
                     if (snow[1]=='3') {
                        toprint+="_";
                    }
                    if (snow[1]=='4') {
                        toprint+=" ";
                    } 
                }
            }
            toprint+=")";
            if(snow[rightarmes]=='2'){
                toprint+="/";
            }
            else
            {
                toprint+=" ";
            }
            thesnoemen+=toprint+"\n";
            i=rightarmes;
        }
        if(i==rightarmes){
            string toprint;
             if(snow[leftarmes]=='1'){
                    toprint+="<(";
                    }
                    if (snow[leftarmes]=='3') {
                        toprint+="/(";
                    }
                    if (snow[leftarmes]=='2'||snow[leftarmes]=='4') {
                        toprint+=" (";
                    } 
                    if(snow[torso]=='1'){
                    toprint+=" : )";
                    }
                    else if (snow[torso]=='2') {
                        toprint+="] [)";
                    }
                    else if (snow[torso]=='3') {
                        toprint+="> <)";
                    }
                    else{
                        toprint+="   )";
                    } 
                    if(snow[rightarmes]=='1'){
                    toprint+=">";
                    }
                    else if (snow[rightarmes]=='3') {
                        toprint+="\\";
                    }
                    else{
                        toprint+=" ";
                    } 
              thesnoemen+=toprint+"\n";     
            i=base;
        }
    if(i==base){
         string toprint;
        if(snow[base]=='1'){
                    toprint+="( : ) ";
                    }
                    if (snow[base]=='2') {
                        toprint+="(\" \") ";
                    }
                    if (snow[base]=='3') {
                        toprint+="(___) ";
                    }
                    if (snow[base]=='4') {
                        toprint+="(   ) ";
                    } 
                    thesnoemen+=toprint;
    }
    }
    return thesnoemen;
}
}



