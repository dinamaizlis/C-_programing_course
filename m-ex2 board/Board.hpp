#include <string>
#include <map>
#include <climits>
#include "Direction.hpp"


namespace ariel{

    class Board{

        public:
        std::map<unsigned int, std::map<unsigned int, char>> my_board;
        unsigned int min_row=UINT_MAX;
        unsigned int min_col=UINT_MAX;
        unsigned int max_row=0;
        unsigned int max_col=0;

        Board(){}
        ~Board(){}
        
        void post(unsigned int row,unsigned int col, Direction direction, std::string const &message);

        std::string read(unsigned int row, unsigned int  col, Direction direction, unsigned int length);
        
        void show();
    };

}
