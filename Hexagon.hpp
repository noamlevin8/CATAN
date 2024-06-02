//
// Created by Noam Levin on 02/06/2024.
//
// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"

using namespace std;

namespace ariel {

    class Hexagon {

        // Fields
        int _num;
        string _type;
        vector<Edge&> _edges;

        public:
                Hexagon(int n, string t) { this->_num = n; this->_type = t;};
    };
}