// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include "Board.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <string>

using namespace std;

namespace ariel{

    class Player
    {
        // Fields

        string _name; // Players name
        int _index; // Players index in the game
        string _color; // Players colors

        int _points = 2;
        int _numOfCities = 0;
        int _numOfSettlements = 2;

        int _numOfVictoryPoints = 0;
        int _numOfKnights = 0;
        int _numOfMonopoly = 0;
        int _numOfBuild2Roads = 0;
        int _numOfYearOfPlenty = 0;
        int _numOfUsedKnights = 0;

        int _numOfWood = 0;
        int _numOfBrick = 0;
        int _numOfSheep = 0;
        int _numOfStone = 0;
        int _numOfWheat = 0;

        public:
                static int _turn; // Current turn index

                Player(string name, string color);
                ~Player();

                void placeCity(unsigned int place_id, Board& board);
                void placeSettlement(unsigned int place_id, Board& board);
                bool placeRoad(unsigned int from, unsigned int to, Board& board); // Bool because of the first turn
                int rollDice();
                inline static void endTurn() {_turn = (_turn % 3) + 1;};
                void trade(Player& p2, string give, string get, int give_num, int get_num);
                void tradeBank(string give, string get);
                void printPoints() const;

                inline string getName() const {return this->_name;};
                inline string getColor() const {return this->_color;};
                inline void setIdx(int num) {this->_index = num;};
                inline int getIdx() const {return this->_index;};
                inline int getNumOfSettlements() const {return this->_numOfSettlements;};
                inline int getNumOfResources() const {return this->_numOfWheat + this->_numOfStone + this->_numOfSheep + this->_numOfBrick + this->_numOfWood;}

                inline void addWood(int num) {this->_numOfWood += num;};
                inline void subWood(int num) {this->_numOfWood -= num;};

                inline void addBrick(int num) {this->_numOfBrick += num;};
                inline void subBrick(int num) {this->_numOfBrick -= num;};

                inline void addSheep(int num) {this->_numOfSheep += num;};
                inline void subSheep(int num) {this->_numOfSheep -= num;};

                inline void addStone(int num) {this->_numOfStone += num;};
                inline void subStone(int num) {this->_numOfStone -= num;};

                inline void addWheat(int num) {this->_numOfWheat += num;};
                inline void subWheat(int num) {this->_numOfWheat -= num;};

                inline int getNumOfWood() const {return this->_numOfWood;};
                inline int getNumOfBrick() const {return this->_numOfBrick;};
                inline int getNumOfSheep() const {return this->_numOfSheep;};
                inline int getNumOfStone() const {return this->_numOfStone;};
                inline int getNumOfWheat() const {return this->_numOfWheat;};

                inline int getPoints() const {return this->_points;};

                inline int getNumOfMonopoly() const {return this->_numOfMonopoly;};
                inline int getNumOfBuild2Roads() const {return this->_numOfBuild2Roads;};
                inline int getNumOfYearOfPlenty() const {return this->_numOfYearOfPlenty;};
                inline int getNumOfKnights() const {return this->_numOfKnights;};
                inline int getNumUsedKnights() const {return this->_numOfUsedKnights;};
                inline int getNumOfVictoryPoints() const {return this->_numOfVictoryPoints;};

                inline void addMonopoly(int num) { this->_numOfMonopoly += num;};
                inline void add2Roads(int num) { this->_numOfBuild2Roads += num;};
                inline void addYearOfPlenty(int num) { this->_numOfYearOfPlenty += num;};
                inline void addKnight(int num) { this->_numOfKnights += num;};
                inline void useKnight() { this->_numOfUsedKnights++;};
                inline void KnightsPoints() { this->_points += 2;};
                inline void addVictoryPoint(int num) { this->_numOfVictoryPoints += num; this->_points += num;};

                inline void subMonopoly(int num) { this->_numOfMonopoly -= num;};
                inline void sub2Roads(int num) { this->_numOfBuild2Roads -= num;};
                inline void subYearOfPlenty(int num) { this->_numOfYearOfPlenty -= num;};
                inline void subKnight(int num) { this->_numOfKnights -= num;};
                inline void subVictoryPoint(int num) { this->_numOfVictoryPoints -= num; this->_points--;};
    };
}