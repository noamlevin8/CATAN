//
// Created by Noam Levin on 02/06/2024.
//
// ID: 326662574
// MAIL: noamlevin11@gmail.com

#pragma once
#include "Vertex.hpp"

namespace ariel {

    class Edge {
        Vertex& _v1;
        Vertex& _v2;

        public:
                Edge(Vertex& v1, Vertex & v2) : _v1(v1), _v2(v2) {};
    };

}