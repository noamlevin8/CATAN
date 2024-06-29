// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::to_string;
using std::vector;
using std::string;

namespace ariel {

    class Place {

        vector<string> _type;
        vector<unsigned int> _num;
        vector<unsigned int> _neighbors;
        vector<string> _roads;
        string _owner = "";
        unsigned int _id;

    public:
            Place();
            ~Place();

            inline vector<unsigned int> getNeighbors() const { return _neighbors; }
            inline vector<string> getRoads() const { return _roads; }
            void add_info(vector<string> type, vector<unsigned int> num, vector<unsigned int> neighbors, unsigned int id);
            inline void setOwner(string color){ this->_owner = color; };
            inline void setRoadOwner(string color, unsigned int i){ this->_roads[i] = color; };
            inline string getRoadOwner(unsigned int i) const { return _roads[i]; };
            inline string getOwner() const { return this->_owner; };
            string diceInPlace(int result);
            friend std::ostream& operator<<(std::ostream& os, Place& p);
            inline bool operator==(Place other) const { return (*this)._id == other.getId(); };
            bool closeTo(Place other);
            string getType(unsigned int place);
            inline unsigned int getId() const { return this->_id; };
            inline vector<string> getAllTypes() {return this->_type;};
    };
}
