// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Player.hpp"

namespace ariel {
    int Player::_turn = 1;

    Player::Player(string name, string color) {
        this->_name = name;
        this->_index = 0;
        this->_color = color;
        _turn = 1;
    }

    Player::~Player() {}

    // need to check for 2 roads
    void Player::placeSettlement(unsigned int place_id, Board& board) {
//        if (_turn != this->_index) {
////            throw invalid_argument("Not your turn!");
//            cout << "Not your turn!" << endl;
//            return;
//        }

        if (this->_numOfBrick < 1 || this->_numOfWood < 1 || this->_numOfSheep < 1 || this->_numOfWheat < 1) {
//            throw invalid_argument("You don't have enough resources!");
            cout << "You don't have enough resources!" << endl;
            return;
        }

        //Check for valid place
        if(place_id < 1 || place_id > 54) {
            cout << "Not a valid place id" << endl;
            return;
        }

        if(board.getPlace(place_id)->getOwner() != ""){
            cout << "This place is not empty" << endl;
            return;
        }

        vector<unsigned int> neighbors = board.getPlace(place_id)->getNeighbors();

        for(unsigned int i = 0; i < neighbors.size(); i++){
            if(board.getPlace(neighbors[i])->getOwner() != ""){
                cout << "There is a neighbor settlement" << endl;
                return;
            }
        }

        vector<string> roads = board.getPlace(place_id)->getRoads();
        bool neighborRoad = false;

        for(unsigned int i = 0; i < roads.size(); i++){
            if(roads[i] == this->_color){ neighborRoad = true; }
        }

        if(!neighborRoad){
            cout << "Cant place a settlement that is not connected to a road" << endl;
            return;
        }


        this->_numOfBrick--;
        this->_numOfWood--;
        this->_numOfSheep--;
        this->_numOfWheat--;

        //Place the settlement
        board.setOwner(place_id, this->_color);

        this->_numOfSettlements++;
        this->_points++;
    }

    void Player::placeCity(unsigned int place_id, Board& board) {
//        if (_turn != this->_index) {
////            throw invalid_argument("Not your turn!");
//            cout << "Not your turn!" << endl;
//            return;
//        }

        if (this->_numOfStone < 3 || this->_numOfWheat < 2) {
//            throw invalid_argument("You don't have enough resources!");
            cout << "You don't have enough resources!" << endl;
            return;
        }

        //Check for valid place
        if(place_id < 1 || place_id > 54) {
            cout << "Not a valid place id" << endl;
            return;
        }

        if(board.getPlace(place_id)->getOwner() != this->_color){
            cout << "This place is not yours" << endl;
            return;
        }

        this->_numOfStone -= 3;
        this->_numOfWheat -= 2;

        //Place the city
        string c = this->_color;
        board.setOwner(place_id, c.replace(2, 2, "1;"));

        this->_numOfCities++;
        this->_numOfSettlements--;
        this->_points++;
    }

    bool Player::placeRoad(unsigned int from, unsigned int to, Board& board) {
//        if (_turn != this->_index){
////            throw invalid_argument("Not your turn!");
//            cout << "Not your turn!" << endl;
//            return;
//        }

        if (this->_numOfBrick < 1 || this->_numOfWood < 1) {
//            throw invalid_argument("You don't have 1 Brick and 1 Wood!");
            cout << "You don't have 1 Brick and 1 Wood!" << endl;
            return false;
        }

        //Check for valid place
        if(from < 1 || from > 54 || to < 1 || to > 54){
            cout << "Not a valid place for a road" << endl;
            return false;
        }

        if(!board.getPlace(from)->closeTo(*board.getPlace(to)) && !board.getPlace(to)->closeTo(*board.getPlace(from))){
            cout << "There is no road from " << from << " to " << to << endl;
            return false;
        }

        vector<string> roads = board.getPlace(from)->getRoads();
        bool neighborRoad = false;

        for(unsigned int i = 0; i < roads.size(); i++){
            if(roads[i] == this->_color){ neighborRoad = true; }
        }

        roads = board.getPlace(to)->getRoads();

        for(unsigned int i = 0; i < roads.size(); i++){
            if(roads[i] == this->_color){ neighborRoad = true; }
        }

        if(!neighborRoad){
            cout << "Cant place a road that is not connected to a settlement or a road" << endl;
            return false;
        }

        //Place the road
        if(this->_color == board.getPlace(from)->getOwner() || this->_color == board.getPlace(to)->getOwner()){
            vector<unsigned int> neighbors = board.getPlace(from)->getNeighbors();

            for(unsigned int i = 0; i < neighbors.size(); i++){
                if(board.getPlace(neighbors[i]) == board.getPlace(to)){
                    if(board.getPlace(from)->getRoadOwner(i) == ""){
                        board.getPlace(from)->setRoadOwner(this->_color, i);

                        vector<unsigned int> neighbors2 = board.getPlace(to)->getNeighbors();
                        for(unsigned int i = 0; i < neighbors2.size(); i++){
                            if(board.getPlace(neighbors2[i]) == board.getPlace(from)){
                                board.getPlace(to)->setRoadOwner(this->_color, i);
                            }
                        }

                        this->_numOfBrick--;
                        this->_numOfWood--;
                        return true;
                    }
                    cout << "The road is already occupied" << endl;
                    return false;
                }
            }
        }

        if((board.getPlace(from)->getOwner() == "" || this->_color != board.getPlace(from)->getOwner().replace(2, 2, "0;"))
           && (board.getPlace(to)->getOwner() == "" || this->_color != board.getPlace(to)->getOwner().replace(2, 2, "0;"))){
            vector<unsigned int> neighbors = board.getPlace(from)->getNeighbors();

            for(unsigned int i = 0; i < neighbors.size(); i++){
                if(board.getPlace(neighbors[i]) == board.getPlace(to)){
                    if(board.getPlace(from)->getRoadOwner(i) == ""){
                        board.getPlace(from)->setRoadOwner(this->_color, i);

                        vector<unsigned int> neighbors2 = board.getPlace(to)->getNeighbors();
                        for(unsigned int i = 0; i < neighbors2.size(); i++){
                            if(board.getPlace(neighbors2[i]) == board.getPlace(from)){
                                board.getPlace(to)->setRoadOwner(this->_color, i);
                            }
                        }

                        this->_numOfBrick--;
                        this->_numOfWood--;
                        return true;
                    }
                    cout << "The road is already occupied" << endl;
                    return false;
                }
            }
        }
        return false;
    }

    int Player::rollDice() {
//        if (_turn != this->_index)
//            throw invalid_argument("Not your turn!");

        // Create a random device and seed the random number generator
        random_device rd;
        mt19937 gen(rd());

        // Create a uniform integer distribution from 2 to 12
        uniform_int_distribution<> dis(2, 12);

        // Generate a random integer in the range [2, 12]
        int random_number = dis(gen);

        // Output the random number
        cout << "Dice roll result: " << random_number << std::endl;
        return random_number;
    }

    void Player::trade(Player &p2, string give, string get, int give_num, int get_num) {
//        if (_turn != this->_index)
//            throw invalid_argument("Not your turn!");

        if (give == "wood") {
            if (this->_numOfWood < give_num) {
                //throw exception("You don't have enough wood!");
                cout << "You don't have enough wood!" << endl;
                return;
            }

            if (get == "wood") {
                if (p2.getNumOfWood() < get_num) {
                    //throw exception("You don't have enough wood!");
                    cout << "P2 don't have enough wood!" << endl;
                    return;
                }

                this->_numOfWood += get_num;
                p2.subWood(get_num);

                this->_numOfWood -= give_num;
                p2.addWood(give_num);

                return;
            }
            if (get == "brick") {
                if (p2.getNumOfBrick() < get_num) {
                    //throw exception("P2 don't have enough brick!");
                    cout << "P2 don't have enough brick!" << endl;
                    return;
                }

                this->_numOfBrick += get_num;
                p2.subBrick(get_num);

                this->_numOfWood -= give_num;
                p2.addWood(give_num);

                return;
            }
            if (get == "sheep") {
                if (p2.getNumOfSheep() < get_num) {
                    //throw exception("P2 don't have enough sheep!");
                    cout << "P2 don't have enough sheep!" << endl;
                    return;
                }

                this->_numOfSheep += get_num;
                p2.subSheep(get_num);

                this->_numOfWood -= give_num;
                p2.addWood(give_num);

                return;
            }
            if (get == "stone") {
                if (p2.getNumOfStone() < get_num) {
                    //throw exception("P2 don't have enough stone!");
                    cout << "P2 don't have enough stone!" << endl;
                    return;
                }

                this->_numOfStone += get_num;
                p2.subStone(get_num);

                this->_numOfWood -= give_num;
                p2.addWood(give_num);

                return;
            }
            if (get == "wheat") {
                if (p2.getNumOfWheat() < get_num) {
                    //throw exception("P2 don't have enough wheat!");
                    cout << "P2 don't have enough wheat!" << endl;
                    return;
                }

                this->_numOfWheat += get_num;
                p2.subWheat(get_num);

                this->_numOfWood -= give_num;
                p2.addWood(give_num);

                return;
            }
        }


        if (give == "brick") {
            if (this->_numOfBrick < give_num) {
                //throw exception("You don't have enough brick!");
                cout << "You don't have enough brick!" << endl;
                return;
            }

            if (get == "wood") {
                if (p2.getNumOfWood() < get_num) {
                    //throw exception("You don't have enough wood!");
                    cout << "P2 don't have enough wood!" << endl;
                    return;
                }

                this->_numOfWood += get_num;
                p2.subWood(get_num);

                this->_numOfBrick -= give_num;
                p2.addBrick(give_num);

                return;
            }
            if (get == "brick") {
                if (p2.getNumOfBrick() < get_num) {
                    //throw exception("P2 don't have enough brick!");
                    cout << "P2 don't have enough brick!" << endl;
                    return;
                }

                this->_numOfBrick += get_num;
                p2.subBrick(get_num);

                this->_numOfBrick -= give_num;
                p2.addBrick(give_num);

                return;
            }
            if (get == "sheep") {
                if (p2.getNumOfSheep() < get_num) {
                    //throw exception("P2 don't have enough sheep!");
                    cout << "P2 don't have enough sheep!" << endl;
                    return;
                }

                this->_numOfSheep += get_num;
                p2.subSheep(get_num);

                this->_numOfBrick -= give_num;
                p2.addBrick(give_num);

                return;
            }
            if (get == "stone") {
                if (p2.getNumOfStone() < get_num) {
                    //throw exception("P2 don't have enough stone!");
                    cout << "P2 don't have enough stone!" << endl;
                    return;
                }

                this->_numOfStone += get_num;
                p2.subStone(get_num);

                this->_numOfBrick -= give_num;
                p2.addBrick(give_num);

                return;
            }
            if (get == "wheat") {
                if (p2.getNumOfWheat() < get_num) {
                    //throw exception("P2 don't have enough wheat!");
                    cout << "P2 don't have enough wheat!" << endl;
                    return;
                }

                this->_numOfWheat += get_num;
                p2.subWheat(get_num);

                this->_numOfBrick -= give_num;
                p2.addBrick(give_num);

                return;
            }
        }


        if (give == "sheep") {
            if (this->_numOfSheep < give_num) {
                //throw exception("You don't have enough sheep!");
                cout << "You don't have enough sheep!" << endl;
                return;
            }

            if (get == "wood") {
                if (p2.getNumOfWood() < get_num) {
                    //throw exception("You don't have enough wood!");
                    cout << "P2 don't have enough wood!" << endl;
                    return;
                }

                this->_numOfWood += get_num;
                p2.subWood(get_num);

                this->_numOfSheep -= give_num;
                p2.addSheep(give_num);

                return;
            }
            if (get == "brick") {
                if (p2.getNumOfBrick() < get_num) {
                    //throw exception("P2 don't have enough brick!");
                    cout << "P2 don't have enough brick!" << endl;
                    return;
                }

                this->_numOfBrick += get_num;
                p2.subBrick(get_num);

                this->_numOfSheep -= give_num;
                p2.addSheep(give_num);

                return;
            }
            if (get == "sheep") {
                if (p2.getNumOfSheep() < get_num) {
                    //throw exception("P2 don't have enough sheep!");
                    cout << "P2 don't have enough sheep!" << endl;
                    return;
                }

                this->_numOfSheep += get_num;
                p2.subSheep(get_num);

                this->_numOfSheep -= give_num;
                p2.addSheep(give_num);

                return;
            }
            if (get == "stone") {
                if (p2.getNumOfStone() < get_num) {
                    //throw exception("P2 don't have enough stone!");
                    cout << "P2 don't have enough stone!" << endl;
                    return;
                }

                this->_numOfStone += get_num;
                p2.subStone(get_num);

                this->_numOfSheep -= give_num;
                p2.addSheep(give_num);

                return;
            }
            if (get == "wheat") {
                if (p2.getNumOfWheat() < get_num) {
                    //throw exception("P2 don't have enough wheat!");
                    cout << "P2 don't have enough wheat!" << endl;
                    return;
                }

                this->_numOfWheat += get_num;
                p2.subWheat(get_num);

                this->_numOfSheep -= give_num;
                p2.addSheep(give_num);

                return;
            }
        }


        if (give == "stone") {
            if (this->_numOfStone < give_num) {
                //throw exception("You don't have enough stone!");
                cout << "You don't have enough stone!" << endl;
                return;
            }

            if (get == "wood") {
                if (p2.getNumOfWood() < get_num) {
                    //throw exception("You don't have enough wood!");
                    cout << "P2 don't have enough wood!" << endl;
                    return;
                }

                this->_numOfWood += get_num;
                p2.subWood(get_num);

                this->_numOfStone -= give_num;
                p2.addStone(give_num);

                return;
            }
            if (get == "brick") {
                if (p2.getNumOfBrick() < get_num) {
                    //throw exception("P2 don't have enough brick!");
                    cout << "P2 don't have enough brick!" << endl;
                    return;
                }

                this->_numOfBrick += get_num;
                p2.subBrick(get_num);

                this->_numOfStone -= give_num;
                p2.addStone(give_num);

                return;
            }
            if (get == "sheep") {
                if (p2.getNumOfSheep() < get_num) {
                    //throw exception("P2 don't have enough sheep!");
                    cout << "P2 don't have enough sheep!" << endl;
                    return;
                }

                this->_numOfSheep += get_num;
                p2.subSheep(get_num);

                this->_numOfStone -= give_num;
                p2.addStone(give_num);

                return;
            }
            if (get == "stone") {
                if (p2.getNumOfStone() < get_num) {
                    //throw exception("P2 don't have enough stone!");
                    cout << "P2 don't have enough stone!" << endl;
                    return;
                }

                this->_numOfStone += get_num;
                p2.subStone(get_num);

                this->_numOfStone -= give_num;
                p2.addStone(give_num);

                return;
            }
            if (get == "wheat") {
                if (p2.getNumOfWheat() < get_num) {
                    //throw exception("P2 don't have enough wheat!");
                    cout << "P2 don't have enough wheat!" << endl;
                    return;
                }

                this->_numOfWheat += get_num;
                p2.subWheat(get_num);

                this->_numOfStone -= give_num;
                p2.addStone(give_num);

                return;
            }
        }


        if (give == "wheat") {
            if (this->_numOfWheat < give_num) {
                //throw exception("You don't have enough wheat!");
                cout << "You don't have enough wheat!" << endl;
                return;
            }

            if (get == "wood") {
                if (p2.getNumOfWood() < get_num) {
                    //throw exception("You don't have enough wood!");
                    cout << "P2 don't have enough wood!" << endl;
                    return;
                }

                this->_numOfWood += get_num;
                p2.subWood(get_num);

                this->_numOfWheat -= give_num;
                p2.addWheat(give_num);

                return;
            }
            if (get == "brick") {
                if (p2.getNumOfBrick() < get_num) {
                    //throw exception("P2 don't have enough brick!");
                    cout << "P2 don't have enough brick!" << endl;
                    return;
                }

                this->_numOfBrick += get_num;
                p2.subBrick(get_num);

                this->_numOfWheat -= give_num;
                p2.addWheat(give_num);

                return;
            }
            if (get == "sheep") {
                if (p2.getNumOfSheep() < get_num) {
                    //throw exception("P2 don't have enough sheep!");
                    cout << "P2 don't have enough sheep!" << endl;
                    return;
                }

                this->_numOfSheep += get_num;
                p2.subSheep(get_num);

                this->_numOfWheat -= give_num;
                p2.addWheat(give_num);

                return;
            }
            if (get == "stone") {
                if (p2.getNumOfStone() < get_num) {
                    //throw exception("P2 don't have enough stone!");
                    cout << "P2 don't have enough stone!" << endl;
                    return;
                }

                this->_numOfStone += get_num;
                p2.subStone(get_num);

                this->_numOfWheat -= give_num;
                p2.addWheat(give_num);

                return;
            }
            if (get == "wheat") {
                if (p2.getNumOfWheat() < get_num) {
                    //throw exception("P2 don't have enough wheat!");
                    cout << "P2 don't have enough wheat!" << endl;
                    return;
                }

                this->_numOfWheat += get_num;
                p2.subWheat(get_num);

                this->_numOfWheat -= give_num;
                p2.addWheat(give_num);

                return;
            }
        }
    }

    void Player::tradeBank(string give, string get){
        if(give == "wood"){
            if (this->_numOfWood < 4) {
                //throw exception("You don't have enough wood!");
                cout << "You don't have enough wood!" << endl;
                return;
            }

            if(get == "brick"){
                addBrick(1);
                subWood(4);
            } else if(get == "sheep"){
                addSheep(1);
                subWood(4);
            } else if(get == "stone"){
                addStone(1);
                subWood(4);
            } else if(get == "wheat"){
                addWheat(1);
                subWood(4);
            } else
                cout << "Not a valid get value!" << endl;
        } else if(give == "brick"){
            if (this->_numOfBrick < 4) {
                //throw exception("You don't have enough wood!");
                cout << "You don't have enough brick!" << endl;
                return;
            }

            if(get == "wood"){
                addWood(1);
                subBrick(4);
            } else if(get == "sheep"){
                addSheep(1);
                subBrick(4);
            } else if(get == "stone"){
                addStone(1);
                subBrick(4);
            } else if(get == "wheat"){
                addWheat(1);
                subBrick(4);
            } else
                cout << "Not a valid get value!" << endl;
        } else if(give == "sheep"){
            if (this->_numOfSheep < 4) {
                //throw exception("You don't have enough wood!");
                cout << "You don't have enough sheep!" << endl;
                return;
            }

            if(get == "wood"){
                addWood(1);
                subSheep(4);
            } else if(get == "brick"){
                addBrick(1);
                subSheep(4);
            } else if(get == "stone"){
                addStone(1);
                subSheep(4);
            } else if(get == "wheat"){
                addWheat(1);
                subSheep(4);
            } else
                cout << "Not a valid get value!" << endl;
        } else if(give == "stone"){
            if (this->_numOfStone < 4) {
                //throw exception("You don't have enough wood!");
                cout << "You don't have enough stone!" << endl;
                return;
            }

            if(get == "wood"){
                addWood(1);
                subStone(4);
            } else if(get == "brick"){
                addBrick(1);
                subStone(4);
            } else if(get == "sheep"){
                addSheep(1);
                subStone(4);
            } else if(get == "wheat"){
                addWheat(1);
                subStone(4);
            } else
                cout << "Not a valid get value!" << endl;
        } else if(give == "wheat"){
            if (this->_numOfWheat < 4) {
                //throw exception("You don't have enough wood!");
                cout << "You don't have enough wheat!" << endl;
                return;
            }

            if(get == "wood"){
                addWood(1);
                subWheat(4);
            } else if(get == "brick"){
                addBrick(1);
                subWheat(4);
            } else if(get == "sheep"){
                addSheep(1);
                subWheat(4);
            } else if(get == "stone"){
                addStone(1);
                subWheat(4);
            } else
                cout << "Not a valid get value!" << endl;
        } else
            cout << "Not a valid give value!" << endl;
    }

//    void Player::buyDevelopmentCard() {
////        if (_turn != this->_index)
////            throw invalid_argument("Not your turn!");
//
//        if (this->_numOfSheep < 1 || this->_numOfWheat < 1 || this->_numOfStone < 1) {
//            //throw exception("You don't have enough resources!");
//            cout << "You don't have enough resources!" << endl;
//            return;
//        }
//
//        // Buy card
//        this->_numOfSheep--;
//        this->_numOfWheat--;
//        this->_numOfStone--;
//    }

    void Player::printPoints() const {
        cout << this->_name << " has " << this->_points;
        cout << " points because he/she has: " << endl;
        cout << this->_numOfSettlements << " settlements" << endl;
        cout << this->_numOfCities << " cities" << endl;
        if (this->_numOfKnights == 3)
            cout << "2 points from the largest army card" << endl;
        cout << this->_numOfVictoryPoints << " victory points" << endl;
    }

//    void useCard(Board &board, string type){
//
//    }
}