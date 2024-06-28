// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <random>
#include <chrono>
#include <algorithm>

#include "Player.hpp"
#include "Board.hpp"
#include "Card.hpp"

using namespace std;

namespace ariel {

    class Catan
    {
        // Fields

        Player* _p1;
        Player* _p2;
        Player* _p3;
        Board _GameBoard;
        stack<unique_ptr<Card>> _cards;

        public:
                Catan(Player& p1, Player& p2, Player& p3);
                ~Catan();
                Player* ChooseStartingPlayer();
                Board* getBoard();
                void printWinner() const;
                bool hasWinner() const;
                Player* endTurn () const;
                void updateResources(int dice);
                Player* getPlayer(int i) const;
                void firstTurn(Player &p);
                void firstSettlements(Player &p, bool resources);
                void addFirstResources(Player &p, unsigned int place);
                void buyDevelopmentCard(Player &p);
                void useDevelopmentCard(Player& p);
    };
}