// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Catan.hpp"

using namespace std;

namespace ariel {

    Catan::~Catan() {}

    void Catan::ChooseStartingPlayer() {
        // Create a random device and seed the random number generator
        random_device rd;
        mt19937 gen(rd());

        // Create a uniform integer distribution from 1 to 3
        uniform_int_distribution<> dis(1, 3);

        // Generate a random integer in the range [1, 3]
        int random_number = dis(gen);

        if (random_number == 1) {
            _p1.setIdx(1);
            _p2.setIdx(2);
            _p3.setIdx(3);
            cout << "The player that starts is: " << _p1.getName() << endl;
        } else if (random_number == 2) {
            _p2.setIdx(1);
            _p3.setIdx(2);
            _p1.setIdx(3);
            cout << "The player that starts is: " << _p2.getName() << endl;
        } else {
            _p3.setIdx(1);
            _p1.setIdx(2);
            _p2.setIdx(3);
            cout << "The player that starts is: " << _p3.getName() << endl;
        }
    }

    Board Catan::getBoard() const {
        return this->_GameBoard;
    }

    void Catan::printWinner() const {
        if (_p1.getPoints() >= 10)
            cout << "The winner is: " << _p1.getName() << endl;

        else if (_p2.getPoints() >= 10)
            cout << "The winner is: " << _p2.getName() << endl;

        else if (_p3.getPoints() >= 10)
            cout << "The winner is: " << _p3.getName() << endl;

        else
            cout << "None of the players has 10 points" << endl;
    }
}