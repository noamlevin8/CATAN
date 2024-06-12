// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Catan.hpp"

using namespace std;

namespace ariel {

    void Catan::ChooseStartingPlayer() {
        // Create a random device and seed the random number generator
        random_device rd;
        mt19937 gen(rd());

        // Create a uniform integer distribution from 1 to 3
        uniform_int_distribution<> dis(1, 3);

        // Generate a random integer in the range [1, 3]
        int random_number = dis(gen);

        // Output the random number
        cout << "The player that starts is: " << random_number << endl;

        if (random_number == 1) {
            _p1.setIdx(1);
            _p2.setIdx(2);
            _p3.setIdx(3);
        } else if (random_number == 2) {
            _p2.setIdx(1);
            _p3.setIdx(2);
            _p1.setIdx(3);
        } else {
            _p3.setIdx(1);
            _p1.setIdx(2);
            _p2.setIdx(3);
        }
    }

    Board Catan::getBoard() const {

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