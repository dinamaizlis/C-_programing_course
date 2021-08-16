#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <string>


using namespace std;

namespace ariel{
    void Board::post(unsigned int row, unsigned int col, Direction direction, string const &message){
        if(message.empty()){
            return;
        }
        if(this->min_col>col){
            this->min_col= col;
        }
        if(this->min_row>row){
                this->min_row= row;
        }
        if (direction == Direction::Horizontal){
            if (this->max_row<row){
                this->max_row= row;
            }
            if (this->max_col<message.length()+col){
                this->max_col=message.length()+col;
            }
            for (unsigned int i=0; i<message.length(); ++i){
                this->my_board[row][col+i]=message.at(i);
            }   
        }
        else{
            if (this->max_row<message.length()+row){
                this->max_row= message.length()+row;
            }
            if (this->max_col < col){
                this->max_col = col;
            }

            for (unsigned int i=0; i<message.length(); ++i){
                this->my_board[row+i][col]=message.at(i);
            } 
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length){
        string ans;
        if (direction== Direction::Horizontal){
            for (unsigned int i=0; i<length; ++i){
                if(this->my_board[row][col+i] != 0){
                    ans=ans+this->my_board[row][col+i];
                }
                else{
                    ans=ans+ '_';
                }

            }
        }
        else{
            for (unsigned int i=0; i<length; ++i){  
                if(this->my_board[row+i][col] != 0){
                    ans=ans+this->my_board[row+1][col];
                }
                else{
                    ans=ans+ '_';
                }
            } 
        }        
        return ans;
    }

    void Board::show(){
        for (unsigned int row = this->min_row;  row <= this->max_row;   ++row){
            for (unsigned int col = this->min_col; col<=this->max_col; ++col){
                if(this->my_board[row][col] != 0){
                    cout<<this->my_board[row][col];
                }
                else{
                    cout<<'_';
                }
            }
            cout << endl;
        }
    };
}
