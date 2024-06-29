// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include "Place.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include <chrono>

using std::cout;
using std::endl;
using std::to_string;
using std::vector;
using std::string;

namespace ariel{
    
    class Board
    {
        // Fields
        vector<Place> _places;

    public:
               Board();
               Board(bool test);
               ~Board();

                inline void setOwner(unsigned int place, string color){ this->_places[place-1].setOwner(color); };
                inline Place* getPlace(unsigned int i){ return &_places[i-1]; };
                string road(unsigned int from, unsigned int to, string c);
                void printBoard();
    };
}