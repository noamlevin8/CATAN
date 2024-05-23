// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Player.hpp"

using namespace ariel;

Player::Player(string name)
{
    this->_name = name; 
    this->_turn = 1; 
    this->_index = 0; 
}

void Player::placeSettelemnt(vector<string> places, vector<int> placesNum, Board board)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");
}

void Player::placeRoad(vector<string> places, vector<int> placesNum, Board board)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");
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
}

void Player::trade(Player& p2, string give, string get, int give_num, int get_num)
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(give == "wood")
    {
        this->_numOfWood -= give_num;
        p2._numOfWood += give_num;
    }
    if(give == "brick")
    {
        this->_numOfBrick -= give_num;
        p2._numOfBrick += give_num;
    }
    if(give == "sheep")
    {
        this->_numOfSheep -= give_num;
        p2._numOfSheep += give_num;
    }
    if(give == "stone")
    {
        this->_numOfStone -= give_num;
        p2._numOfStone += give_num;
    }
    if(give == "wheat")
    {
        this->_numOfWheat -= give_num;
        p2._numOfWheat += give_num;
    }

    if(get == "wood")
    {
        this->_numOfWood += get_num;
        p2._numOfWood -= get_num;
    }
    if(get == "brick")
    {
        this->_numOfBrick += get_num;
        p2._numOfBrick -= get_num;
    }
    if(get == "sheep")
    {
        this->_numOfSheep += get_num;
        p2._numOfSheep -= get_num;
    }
    if(get == "stone")
    {
        this->_numOfStone += get_num;
        p2._numOfStone -= get_num;
    }
    if(get == "wheat")
    {
        this->_numOfWheat += get_num;
        p2._numOfWheat -= get_num;
    }
}

void Player::buyDevelopmentCard()
{
    if(Player::getTurn() != this->_index)
        throw invalid_argument("Not your turn!");

    if(this->_numOfSheep > 0 && this->_numOfWheat > 0 && this->_numOfStone > 0)
    {
        // Buy card
        this->_numOfSheep--;
        this->_numOfWheat--;
        this->_numOfStone--;
    }
}

void Player::printPoints()
{
    cout << this->_name << " has " << this->_points;
    cout << " points because he/she has: ";
    cout << this->_numOfSettelments << " settelments and ";
    cout << this->_numOfBonusPoints << " bonus points" << endl;
}