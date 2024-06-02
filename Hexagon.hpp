//
// Created by Noam Levin on 02/06/2024.
//
// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace ariel {

    class Hexagon {

        // Fields
        int _num;
        string type;
        vector<Point> _vertices;
        vector<Edge> _edges;
    };
}