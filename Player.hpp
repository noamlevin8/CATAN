// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include "Board.hpp"

using namespace std;

namespace ariel{

    class Player
    {
        // Fields

        string _name; // Players name
        int _index; // Players index in the game
        
        int _points = 0; // Players number of points
        int _numOfSettelments = 0;
        int _numOfBonusPoints = 0;

        int _numOfWood = 0;
        int _numOfBrick = 0;
        int _numOfSheep = 0;
        int _numOfStone = 0;
        int _numOfWheat = 0;

        public:
                static int _turn; // Current turn index

                Player(string name); // Constructor
                void placeSettelement(vector<string> places, vector<int> placesNum, Board board);
                void placeRoad(vector<string> places, vector<int> placesNum, Board board);
                void rollDice();
                inline static void endTurn() {_turn = (_turn % 3) + 1;};
                void trade(Player& p2, string give, string get, int give_num, int get_num);
                void buyDevelopmentCard();
                void printPoints() const;

                inline string getName() const {return this->_name;};
                inline static int getTurn() const {return _turn;};
                inline void setIdx(int num) {this->_index = num;};

                // inline void addWood(int num) {this->_numOfWood += num;};
                // inline void subWood(int num) {this->_numOfWood -= num;};

                // inline void addBrick(int num) {this->_numOfBrick += num;};
                // inline void subBrick(int num) {this->_numOfBrick -= num;};

                // inline void addSheep(int num) {this->_numOfSheep += num;};
                // inline void subSheep(int num) {this->_numOfSheep -= num;};

                // inline void addStone(int num) {this->_numOfStone += num;};
                // inline void subStone(int num) {this->_numOfStone -= num;};

                // inline void addWheat(int num) {this->_numOfWheat += num;};
                // inline void subWheat(int num) {this->_numOfWheat -= num;};

                inline int getPoints() const {return this->_points;};
    };
}