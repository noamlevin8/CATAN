// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include "Board.hpp"

using namespace std;

namespace ariel{

    class Player
    {
        // Fields

        string _name; // Players name

        public:
                inline Player(string name) {this->_name = name;}; // Inline constructor
                void placeSettelemnt(vector<string> places, vector<int> placesNum, Board board);
                void placeRoad(vector<string> places, vector<int> placesNum, Board board);
                void rollDice();
                void endTurn();
                void trade(Player p2, string give, string get, int give_num, int get_num);
                void buyDevelopmentCard();
                void printPoints();
    };
}