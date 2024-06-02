// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ariel{
    
    class Board
    {
        // Fields
        vector<vector<string>> _CatanBoard;
        vector<vector<size_t>> _numbers;
        vector<Hexagon> _cBoard;

        public:
               Board(); 
    };
}