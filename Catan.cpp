// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Catan.hpp"

using namespace std;

namespace ariel {

    Catan::~Catan() {}

    Player& Catan::ChooseStartingPlayer() {
        // Create a random device and seed the random number generator
        random_device rd;
        mt19937 gen(rd());

        // Create a uniform integer distribution from 1 to 3
        uniform_int_distribution<> dis(1, 3);

        // Generate a random integer in the range [1, 3]
        int random_number = dis(gen);

        if (random_number == 1) {
            this->_p1.setIdx(1);
            this->_p2.setIdx(2);
            this->_p3.setIdx(3);

            cout << "\nThe player that starts is: " << this->_p1.getName() << endl;
            return this->_p1;
        } else if (random_number == 2) {
            this->_p2.setIdx(1);
            this->_p3.setIdx(2);
            this->_p1.setIdx(3);

            cout << "\nThe player that starts is: " << this->_p2.getName() << endl;
            return this->_p2;
        } else {
            this->_p3.setIdx(1);
            this->_p1.setIdx(2);
            this->_p2.setIdx(3);

            cout << "\nThe player that starts is: " << this->_p3.getName() << endl;
            return this->_p3;
        }
    }

    Board& Catan::getBoard() {
        return this->_GameBoard;
    }

    void Catan::printWinner() const {
        if(!hasWinner())
            return;

        if (this->_p1.getPoints() >= 10)
            cout << "The winner is: " << this->_p1.getName() << endl;

        else if (this->_p2.getPoints() >= 10)
            cout << "The winner is: " << this->_p2.getName() << endl;

        else
            cout << "The winner is: " << this->_p3.getName() << endl;
    }

    bool Catan::hasWinner() const {
        if (this->_p1.getPoints() >= 10 || this->_p2.getPoints() >= 10 || this->_p3.getPoints() >= 10)
            return true;

        cout << "None of the players has 10 points" << endl;
        return false;
    }

    Player& Catan::endTurn() {
        Player::endTurn();
        int turn = Player::_turn;

        if(this->_p1.getIdx() == turn) {
            cout << this->_p1.getName() << "'s turn!" << endl;
            return this->_p1;
        }
        else if(this->_p2.getIdx() == turn) {
            cout << this->_p2.getName() << "'s turn!" << endl;
            return this->_p2;
        }
        else {
            cout << this->_p3.getName() << "'s turn!" << endl;
            return this->_p3;
        }
    }

    void Catan::updateResources(int dice){
        for(unsigned int i = 1; i < 55; i++){
            string typeWithNum = this->_GameBoard.getPlace(i).diceInPlace(dice);

            if(typeWithNum != "0"){
                if(this->_GameBoard.getPlace(i).getOwner() == this->_p1.getColor()){
                    if(typeWithNum == "Wood"){ this->_p1.addWood(1); }
                    if(typeWithNum == "Brick"){ this->_p1.addBrick(1); }
                    if(typeWithNum == "Sheep"){ this->_p1.addSheep(1); }
                    if(typeWithNum == "Stone"){ this->_p1.addStone(1); }
                    if(typeWithNum == "Wheat"){ this->_p1.addWheat(1); }
                }

                if(this->_GameBoard.getPlace(i).getOwner() == this->_p2.getColor()){
                    if(typeWithNum == "Wood"){ this->_p2.addWood(1); }
                    if(typeWithNum == "Brick"){ this->_p2.addBrick(1); }
                    if(typeWithNum == "Sheep"){ this->_p2.addSheep(1); }
                    if(typeWithNum == "Stone"){ this->_p2.addStone(1); }
                    if(typeWithNum == "Wheat"){ this->_p2.addWheat(1); }
                }

                if(this->_GameBoard.getPlace(i).getOwner() == this->_p3.getColor()){
                    if(typeWithNum == "Wood"){ this->_p3.addWood(1); }
                    if(typeWithNum == "Brick"){ this->_p3.addBrick(1); }
                    if(typeWithNum == "Sheep"){ this->_p3.addSheep(1); }
                    if(typeWithNum == "Stone"){ this->_p3.addStone(1); }
                    if(typeWithNum == "Wheat"){ this->_p3.addWheat(1); }
                }
            }
        }
    }

    Player& Catan::getPlayer(int i) const{
        if(i == 1)
            return this->_p1;
        if(i == 2)
            return this->_p2;
//        if(i == 3)
        return this->_p3;

//        cout << "Not a valid number!" << endl;
//        return NULL;
    }

    void Catan::firstTurn(Player &p){
        if(p.getIdx() == this->_p1.getIdx()){
            firstSettlements(this->_p1);
            firstSettlements(this->_p2);
            firstSettlements(this->_p3);
            firstSettlements(this->_p3);
            firstSettlements(this->_p2);
            firstSettlements(this->_p1);
        } else if(p.getIdx() == this->_p2.getIdx()){
            firstSettlements(this->_p2);
            firstSettlements(this->_p3);
            firstSettlements(this->_p1);
            firstSettlements(this->_p1);
            firstSettlements(this->_p3);
            firstSettlements(this->_p2);
        } else{
            firstSettlements(this->_p3);
            firstSettlements(this->_p1);
            firstSettlements(this->_p2);
            firstSettlements(this->_p2);
            firstSettlements(this->_p1);
            firstSettlements(this->_p3);
        }
    }

    void Catan::firstSettlements(Player &p){
        bool valid_place = false, check_nei = true;
        unsigned int place;

        this->_GameBoard.printBoard();
        cout << p.getName() << ", where do you want to build the settlement?" << endl;

        while (!valid_place) {
            cin >> place;
            if (place > 0 && place < 55) {
                if(this->_GameBoard.getPlace(place).getOwner() == "") {
                    vector<unsigned int> neighbors = this->_GameBoard.getPlace(place).getNeighbors();
                    for(unsigned int i = 0; i < neighbors.size(); i++){
                        if(this->_GameBoard.getPlace(neighbors[i]).getOwner() != ""){
                            cout << "Can't place a settlement neighbor to another. Enter new place!" << endl;
                            check_nei = false;
                            break; // breaks from for loop only
                        }
                    }
                    if(check_nei)
                        valid_place = true;
                    else
                        check_nei = true;
                }
                else
                    cout << "The place is not empty!. Enter new place!" << endl;
            } else
                cout << "Not a valid place. Enter new place!" << endl;
        }

        this->_GameBoard.setOwner(place, p.getColor());

        unsigned int to;
        bool valid_road = false;

        cout << "\nNow the road." << endl;
        while (!valid_road){
            cout << "To: " << endl;
            cin >> to;

            if(to < 1 || to > 54){
                cout << "Not a valid place. Try again!" << endl;
                continue;
            }

            if(!this->_GameBoard.getPlace(place).closeTo(this->_GameBoard.getPlace(to))){
                cout << "There's no road between " << place << " and " << to << ". Try again!" << endl;
                continue;
            }

            valid_road = true;
        }

        vector<unsigned int> neighbors = this->_GameBoard.getPlace(to).getNeighbors();
        for(unsigned int i = 0; i < neighbors.size(); i++){
            if(this->_GameBoard.getPlace(neighbors[i]) == this->_GameBoard.getPlace(place)){
                this->_GameBoard.getPlace(to).setRoadOwner(p.getColor(), i);
            }
        }

        neighbors = this->_GameBoard.getPlace(place).getNeighbors();
        for(unsigned int i = 0; i < neighbors.size(); i++){
            if(this->_GameBoard.getPlace(neighbors[i]) == this->_GameBoard.getPlace(to)){
                this->_GameBoard.getPlace(place).setRoadOwner(p.getColor(), i);
            }
        }

//        this->_GameBoard.printBoard();
    }
}