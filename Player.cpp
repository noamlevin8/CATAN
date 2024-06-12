// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Player.hpp"

using namespace ariel;

Player::Player(string name)
{
    this->_name = name; 
    this->_index = 0;
}

void Player::placeSettlement(vector<string> places, vector<int> placesNum, Board board)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(this->_numOfBrick < 1 || this->_numOfWood < 1 || this->_numOfSheep < 1 || this->_numOfWheat < 1)
        throw exception("You don't have enough sources!")

    //Check for valid place

    this->_numOfBrick--;
    this->_numOfWood--;
    this->_numOfSheep--;
    this->_numOfWheat--;

    //Place the settlement

    this->_numOfSettlements++;
    this->_points++;
}

void Player::placeCity(vector <std::string> places, vector<int> placesNum, ariel::Board board)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(this->_numOfStone < 3 || this->_numOfWheat < 2)
        throw exception("You don't have enough sources!")

    //Check for valid place

    this->_numOfStone -= 3;
    this->_numOfWheat -= 2;

    //Place the city

    this->_numOfCities++;
    this->_numOfSettlements--;
    this->_points++;
}

void Player::placeRoad(vector<string> places, vector<int> placesNum, Board board)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(this->_numOfBrick < 1 || this->_numOfWood < 1)
        throw exception("You don't have 1 Brick and 1 Wood!")

    //Check for valid place

    this->_numOfBrick--;
    this->_numOfWood--;

    //Place the road
}

void Player::rollDice()
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    // Create a random device and seed the random number generator
    random_device rd;
    mt19937 gen(rd());
    
    // Create a uniform integer distribution from 2 to 12
    uniform_int_distribution<> dis(2, 12);
    
    // Generate a random integer in the range [2, 12]
    int random_number = dis(gen);
    
    // Output the random number
    cout << "Dice roll result: " << random_number << std::endl;

    //Update players resources
}

void Player::trade(Player& p2, string give, string get, int give_num, int get_num)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(give == "wood")
    {
        if(this->_numOfWood < give_num) {
            //throw exception("You don't have enough wood!");
            cout << "You don't have enough wood!" << endl;
            return;
        }

        this->_numOfWood -= give_num;
        p2.addWood(give_num);
    }
    if(give == "brick")
    {
        if(this->_numOfBrick < give_num) {
            //throw exception("You don't have enough brick!");
            cout << "You don't have enough brick!" << endl;
            return;
        }

        this->_numOfBrick -= give_num;
        p2.addBrick(give_num);
    }
    if(give == "sheep")
    {
        if(this->_numOfSheep < give_num) {
            //throw exception("You don't have enough sheep!");
            cout << "You don't have enough sheep!" << endl;
            return;
        }

        this->_numOfSheep -= give_num;
        p2.addSheep(give_num);
    }
    if(give == "stone")
    {
        if(this->_numOfStone < give_num) {
            //throw exception("You don't have enough stone!");
            cout << "You don't have enough stone!" << endl;
            return;
        }

        this->_numOfStone -= give_num;
        p2.addStone(give_num);
    }
    if(give == "wheat")
    {
        if(this->_numOfWheat < give_num) {
            //throw exception("You don't have enough wheat!");
            cout << "You don't have enough wheat!" << endl;
            return;
        }

        this->_numOfWheat -= give_num;
        p2.addWheat(give_num);
    }

    if(get == "wood")
    {
        if(p2.getNumOfWood() < get_num) {
            //throw exception("You don't have enough wood!");
            cout << "P2 don't have enough wood!" << endl;
            return;
        }

        this->_numOfWood += get_num;
        p2.subWood(get_num);
    }
    if(get == "brick")
    {
        if(p2.getNumOfBrick() < get_num) {
            //throw exception("P2 don't have enough brick!");
            cout << "P2 don't have enough brick!" << endl;
            return;
        }

        this->_numOfBrick += get_num;
        p2.subBrick(get_num);
    }
    if(get == "sheep")
    {
        if(p2.getNumOfSheep() < get_num) {
            //throw exception("P2 don't have enough sheep!");
            cout << "P2 don't have enough sheep!" << endl;
            return;
        }

        this->_numOfSheep += get_num;
        p2.subSheep(get_num);
    }
    if(get == "stone")
    {
        if(p2.getNumOfStone() < get_num) {
            //throw exception("P2 don't have enough stone!");
            cout << "P2 don't have enough stone!" << endl;
            return;
        }

        this->_numOfStone += get_num;
        p2.subStone(get_num);
    }
    if(get == "wheat")
    {
        if(p2.getNumOfWheat() < get_num) {
            //throw exception("P2 don't have enough wheat!");
            cout << "P2 don't have enough wheat!" << endl;
            return;
        }

        this->_numOfWheat += get_num;
        p2.subWheat(get_num);
    }
}

void Player::buyDevelopmentCard()
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(this->_numOfSheep < 1 || this->_numOfWheat < 1 || this->_numOfStone < 1)
    {
        //throw exception("You don't have enough resources!");
        cout << "You don't have enough resources!" << endl;
        return;
    }

    // Buy card
    this->_numOfSheep--;
    this->_numOfWheat--;
    this->_numOfStone--;
}

void Player::printPoints() const
{
    cout << this->_name << " has " << this->_points;
    cout << " points because he/she has: " << endl;
    cout << this->_numOfSettelments << " settlements" << endl;
    cout << this->_numOfCities << " cities" << endl;
    if(this->_numOfPrinces == 3)
        cout << "2 points from the largest army card" << endl;
    cout << this->_numOfBonusPoints << " bonus points" << endl;
}