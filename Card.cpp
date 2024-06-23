// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include "Card.hpp"

namespace ariel{

    Card::~Card() {}

    Monopoly::Monopoly() : Card("Monopoly") {}
    void Monopoly::use_card(ariel::Player &p, ariel::Catan &c) {

    }

    Build2Roads::Build2Roads() : Card("Build 2 Roads") {}
    void Build2Roads::use_card(ariel::Player &p, ariel::Catan &c) {

    }

    YearOfPlenty::YearOfPlenty() : Card("Year of Plenty") {}
    void YearOfPlenty::use_card(ariel::Player &p, ariel::Catan &c) {

    }

    Knight::Knight() : Card("Knight") {}
    void Knight::use_card(ariel::Player &p, ariel::Catan &c) {

    }

    VictoryPoint::VictoryPoint() : Card("Victory Point") {}
    void VictoryPoint::use_card(ariel::Player &p, ariel::Catan &c) {

    }
}
