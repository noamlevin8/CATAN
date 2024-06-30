// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include "Place.hpp"

#define FALSE 0
#define TRUE 1

const std::string RESET = "\033[0m";

namespace ariel {
    Place::Place(){}
    Place::~Place(){}

    void Place::add_info(vector<string> type, vector<unsigned int> num, vector<unsigned int> neighbors, unsigned int id){
        this->_type = type;
        this->_num = num;
        this->_neighbors = neighbors;
        this->_id = id;
        vector<string> empty_roads(neighbors.size(),"");
        this->_roads = empty_roads;
    }

    // Getting the type of the dice result
    string Place::diceInPlace(int result){
        for(unsigned int i = 0; i < this->_num.size(); i++){
            if(this->_num[i] == result){ return this->_type[i]; }
        }
        return "0";
    }

    std::ostream& operator<<(std::ostream& os, Place& p) {
        string spaces = "    ";
        if(p.getId() < 10){ spaces = "     "; }
        os << p.getOwner() << "("<<to_string(p.getId())<<")" << RESET << spaces;
        return os;
    }

    // Checking if another place is close to us on the map
    bool Place::closeTo(Place other){
        for(unsigned int i = 0; i< this->_neighbors.size(); i++){
            if(other.getId() == this->_neighbors[i]){ return true; }
        }
        return false;
    }

    string Place::getType(unsigned int place){
        string spaces = ",";
        if(this->_num[place] < 10){ spaces = ", "; }
        return this->_type[place] + spaces + to_string(this->_num[place]);
    };
}