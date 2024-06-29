// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once

#include "Player.hpp"

#include <iostream>
#include <string>
#include <memory>

namespace ariel {

    class Catan;

    // Main class
    class Card {
        string Card_Type;

        public:
                Card(string type) : Card_Type(type) {};
                virtual ~Card();
                inline string get_cardType() const { return this->Card_Type; };
                virtual void use_card(Player &p, Catan &c) = 0;

    };

    // All the types of cards
    class Monopoly : public Card {
        public:
                Monopoly();
                void use_card(Player &p, Catan &c) override;
    };

    class Build2Roads : public Card {
        public:
                Build2Roads();
                void use_card(Player &p, Catan &c) override;
    };

    class YearOfPlenty : public Card {
        public:
                YearOfPlenty();
                void use_card(Player &p, Catan &c) override;
    };

    class Knight : public Card {
        public:
                Knight();
                void use_card(Player &p, Catan &c) override;
    };

    class VictoryPoint : public Card {
        public:
                VictoryPoint();
                void use_card(Player &p, Catan &c) override;
    };
}