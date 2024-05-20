// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Board.hpp"

using namespace std;

namespace ariel {

    class Catan
    {
        // Fields

        Player _p1;
        Player _p2;
        Player _p3;
        Board _GameBoard;

        public:
                inline Catan(Player p1, Player p2, Player p3) {this->_p1 = p1; this->_p2 = p2; this->_p3 = p3;}; // Problem
                void ChooseStartingPlayer();
                Board getBoard();
                void printWinner();
    };
}