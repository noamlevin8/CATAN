// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Board.hpp"

#define FALSE 0
#define TRUE 1


namespace ariel {

    Board::Board() {
        this->_places = {Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(),
                         Place(), Place(), Place(), Place(),
                         Place(), Place(), Place()};

        vector<unsigned int> nums = {5, 2, 6, 3, 8, 10, 9, 12, 11, 4, 8, 10, 9, 4, 5, 6, 3, 11};
        vector <string> types = {"Wood", "Wood", "Wood", "Wood",
                                 "Wheat", "Wheat", "Wheat", "Wheat",
                                 "Brick", "Brick", "Brick", "Brick",
                                 "Stone", "Stone", "Stone",
                                 "Sheep", "Sheep", "Sheep"};
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(types.begin(), types.end(), std::default_random_engine(seed));
        std::shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));

        this->_places[0].add_info({types[0]}, {nums[0]}, {4, 5}, 1);
        this->_places[1].add_info({types[1]}, {nums[1]}, {5, 6}, 2);
        this->_places[2].add_info({types[2]}, {nums[2]}, {6, 7}, 3);

        this->_places[3].add_info({types[0]}, {nums[0]}, {1, 8}, 4);
        this->_places[4].add_info({types[0], types[1]}, {nums[0], nums[1]}, {1, 2, 9}, 5);
        this->_places[5].add_info({types[1], types[2]}, {nums[1], nums[2]}, {2, 3, 10}, 6);
        this->_places[6].add_info({types[2]}, {nums[2]}, {3, 11}, 7);

        this->_places[7].add_info({types[11], types[0]}, {nums[11], nums[0]}, {4, 12, 13}, 8);
        this->_places[8].add_info({types[12], types[0], types[1]}, {nums[12], nums[0], nums[1]}, {13, 14, 5}, 9);
        this->_places[9].add_info({types[13], types[1], types[2]}, {nums[13], nums[1], nums[2]}, {14, 15, 6}, 10);
        this->_places[10].add_info({types[3], types[2]}, {nums[3], nums[2]}, {15, 16, 7}, 11);

        this->_places[11].add_info({types[11]}, {nums[11]}, {8, 17}, 12);
        this->_places[12].add_info({types[0], types[11], types[12]}, {nums[0], nums[11], nums[12]}, {8, 9, 18}, 13);
        this->_places[13].add_info({types[1], types[12], types[13]}, {nums[1], nums[12], nums[13]}, {9, 10, 19}, 14);
        this->_places[14].add_info({types[2], types[3], types[13]}, {nums[2], nums[3], nums[13]}, {10, 11, 20}, 15);
        this->_places[15].add_info({types[3]}, {nums[3]}, {11, 21}, 16);

        this->_places[16].add_info({types[10], types[11]}, {nums[10], nums[11]}, {12, 22, 23}, 17);
        this->_places[17].add_info({types[17], types[11], types[12]}, {nums[17], nums[11], nums[12]}, {23, 23, 13}, 18);
        this->_places[18].add_info({"Desert", types[12], types[13]}, {7, nums[12], nums[13]}, {24, 25, 14}, 19);
        this->_places[19].add_info({types[14], types[3], types[13]}, {nums[14], nums[3], nums[13]}, {25, 26, 15}, 20);
        this->_places[20].add_info({types[4], types[3]}, {nums[4], nums[3]}, {26, 27, 16}, 21);

        this->_places[21].add_info({types[10]}, {nums[10]}, {17, 28}, 22);
        this->_places[22].add_info({types[10], types[11], types[17]}, {nums[10], nums[11], nums[17]}, {17, 18, 29}, 23);
        this->_places[23].add_info({types[12], types[17], "Desert"}, {nums[12], nums[17], 7}, {18, 19, 30}, 24);
        this->_places[24].add_info({types[13], types[14], "Desert"}, {nums[13], nums[14], 7}, {19, 20, 31}, 25);
        this->_places[25].add_info({types[3], types[4], types[14]}, {nums[3], nums[4], nums[14]}, {20, 21, 32}, 26);
        this->_places[26].add_info({types[4]}, {nums[4]}, {21, 33}, 27);

        this->_places[27].add_info({types[10]}, {nums[10]}, {34, 22}, 28);
        this->_places[28].add_info({types[9], types[10], types[17]}, {nums[9], nums[10], nums[17]}, {34, 35, 23}, 29);
        this->_places[29].add_info({types[16], types[17], "Desert"}, {nums[16], nums[17], 7}, {35, 36, 24}, 30);
        this->_places[30].add_info({types[15], types[14], "Desert"}, {nums[15], nums[14], 7}, {36, 37, 25}, 31);
        this->_places[31].add_info({types[5], types[4], types[14]}, {nums[5], nums[4], nums[14]}, {37, 38, 26}, 32);
        this->_places[32].add_info({types[4]}, {nums[4]}, {38, 27}, 33);

        this->_places[33].add_info({types[9], types[10]}, {nums[9], nums[10]}, {28, 39, 29}, 34);
        this->_places[34].add_info({types[9], types[16], types[17]}, {nums[9], nums[16], nums[17]}, {29, 30, 40}, 35);
        this->_places[35].add_info({types[15], types[16], "Desert"}, {nums[15], nums[16], 7}, {30, 31, 41}, 36);
        this->_places[36].add_info({types[5], types[14], types[15]}, {nums[5], nums[14], nums[15]}, {31, 32, 42}, 37);
        this->_places[37].add_info({types[4], types[5]}, {nums[4], nums[5]}, {32, 33, 43}, 38);

        this->_places[38].add_info({types[9]}, {nums[9]}, {44, 34}, 39);
        this->_places[39].add_info({types[8], types[9], types[16]}, {nums[8], nums[9], nums[16]}, {44, 45, 35}, 40);
        this->_places[40].add_info({types[7], types[15], types[16]}, {nums[7], nums[15], nums[16]}, {45, 46, 36}, 41);
        this->_places[41].add_info({types[6], types[5], types[15]}, {nums[6], nums[5], nums[15]}, {46, 47, 37}, 42);
        this->_places[42].add_info({types[5]}, {nums[5]}, {47, 38}, 43);

        this->_places[43].add_info({types[8], types[9]}, {nums[8], nums[9]}, {48, 39, 40}, 44);
        this->_places[44].add_info({types[7], types[8], types[16]}, {nums[7], nums[8], nums[16]}, {40, 41, 49}, 45);
        this->_places[45].add_info({types[6], types[7], types[15]}, {nums[6], nums[7], nums[15]}, {41, 42, 50}, 46);
        this->_places[46].add_info({types[5], types[6]}, {nums[5], nums[6]}, {42, 43, 51}, 47);

        this->_places[47].add_info({types[8]}, {nums[8]}, {52, 44}, 48);
        this->_places[48].add_info({types[7], types[8]}, {nums[7], nums[8]}, {52, 53, 45}, 49);
        this->_places[49].add_info({types[6], types[7]}, {nums[6], nums[7]}, {53, 54, 46}, 50);
        this->_places[50].add_info({types[6]}, {nums[6]}, {54, 47}, 51);

        this->_places[51].add_info({types[8]}, {nums[8]}, {48, 49}, 52);
        this->_places[52].add_info({types[7]}, {nums[7]}, {49, 50}, 53);
        this->_places[53].add_info({types[6]}, {nums[6]}, {50, 51}, 54);
    }

    Board::~Board() {}

    string Board::road(unsigned int from, unsigned int to, string c) {
        vector<unsigned int> neighbors = this->_places[from].getNeighbors();
        for (unsigned int i = 0; i < neighbors.size(); i++) {
            if (this->_places[neighbors[i] - 1] == this->_places[to]) {
                return this->_places[from].getRoadOwner(i) + c + "\033[0m";
            }
        }
        return c;
    }

    void Board::printBoard() {
        cout << "            " << this->_places[0] << this->_places[1] << this->_places[2] << endl;
        cout << "           " << road(0, 3, "/   ") << road(0, 4, "\\   ") << road(1, 4, "/   ") << road(1, 5, "\\   ") << road(2, 5, "/   ") << road(2, 6, "\\   ") << endl;
        cout << "        " << this->_places[3] << this->_places[4] << this->_places[5] << this->_places[6] << endl;
        cout << "         " << road(3, 7, "|") << this->_places[0].getType(0) << road(4, 8, "|") << this->_places[1].getType(0) << road(5, 9, "|") << this->_places[2].getType(0) << road(6, 10, "|") << endl;
        cout << "        " << this->_places[7] << this->_places[8] << this->_places[9] << this->_places[10] << endl;
        cout << "       " << road(7, 11, "/    ") << road(7, 12, "\\  ") << road(8, 12, "/    ") << road(8, 13, "\\  ") << road(9, 13, "/    ") << road(9, 14, "\\  ") << road(10, 14, "/    ") << road(10, 15, "\\  ") << endl;
        cout << "    " << this->_places[11] << this->_places[12] << this->_places[13] << this->_places[14] << this->_places[15] << endl;
        cout << "     " << road(11, 16, "|") << this->_places[7].getType(0) << road(12, 17, "|") << this->_places[8].getType(0) << road(13, 18, "|") << this->_places[9].getType(0) << road(14, 19, "|") << this->_places[10].getType(0) << road(15, 20, "|") << endl;
        cout << "    " << this->_places[16] << this->_places[17] << this->_places[18] << this->_places[19] << this->_places[20] << endl;
        cout << "   " << road(16, 21, "/    ") << road(16, 22, "\\  ") << road(17, 22, "/    ") << road(17, 23, "\\  ") << road(18, 23, "/    ") << road(18, 24, "\\  ") << road(19, 24, "/    ") << road(19, 25, "\\  ") << road(20, 25, "/    ") << road(20, 26, "\\  ") << endl;
        cout << this->_places[21] << this->_places[22] << this->_places[23] << this->_places[24] << this->_places[25] << this->_places[26] << endl;
        cout << " " << road(21, 27, "|") << this->_places[16].getType(0) << road(22, 28, "|") << this->_places[17].getType(0) << road(23, 29, "|") << this->_places[18].getType(0) << road(24, 30, "|") << this->_places[19].getType(0) << road(25, 31, "|") << this->_places[20].getType(0) << road(26, 32, "|") << endl;
        cout << this->_places[27] << this->_places[28] << this->_places[29] << this->_places[30] << this->_places[31] << this->_places[32] << endl;
        cout << "   " << road(27, 33, "\\    ") << road(28, 33, "/  ") << road(28, 34, "\\    ") << road(29, 34, "/  ") << road(29, 35, "\\    ") << road(30, 35, "/  ") << road(30, 36, "\\    ") << road(31, 36, "/  ") << road(31, 37, "\\    ") << road(32, 37, "/  ") << endl;
        cout << "    " << this->_places[33] << this->_places[34] << this->_places[35] << this->_places[36] << this->_places[37] << endl;
        cout << "     " << road(33, 38, "|") << this->_places[28].getType(0) << road(34, 39, "|") << this->_places[29].getType(0) << road(35, 40, "|") << this->_places[30].getType(0) << road(36, 41, "|") << this->_places[31].getType(0) << road(37, 42, "|") << endl;
        cout << "    " << this->_places[38] << this->_places[39] << this->_places[40] << this->_places[41] << this->_places[42] << endl;
        cout << "       " << road(38, 43, "\\    ") << road(39, 43, "/  ") << road(39, 44, "\\    ") << road(40, 44, "/  ") << road(40, 45, "\\    ") << road(41, 45, "/  ") << road(41, 46, "\\    ") << road(42, 46, "/  ") << endl;
        cout << "        " << this->_places[43] << this->_places[44] << this->_places[45] << this->_places[46] << endl;
        cout << "         " << road(43, 47, "|") << this->_places[39].getType(0) << road(44, 48, "|") << this->_places[40].getType(0) << road(45, 49, "|") << this->_places[41].getType(0) << road(46, 50, "|") << endl;
        cout << "        " << this->_places[47] << this->_places[48] << this->_places[49] << this->_places[50] << endl;
        cout << "           " << road(47, 51, "\\    ") << road(48, 51, "/  ") << road(48, 52, "\\    ") << road(49, 52, "/  ") << road(49, 53, "\\    ") << road(50, 53, "/  ") << endl;
        cout << "            " << this->_places[51] << this->_places[52] << this->_places[53] << "\n\n----------------------------------------------\n\n";
    }
}





//    Board::Board() {
//        this->id = 0;
//        this->resource = "";
//    }
//
//    Board::Board(int id) : id(id), resource(""), vertices(6), edges(6) {
//    }
//
//    Board::~Board() {
//        for (size_t i = 0; i < this->vertices.size(); i++) {
//            if (this->vertices[i] != nullptr) {
//                this->vertices[i]->clearIncidentEdges();
//                this->vertices[i]->clearNeighbors();
//                delete this->vertices[i];
//            }
//        }
//        for (size_t i = 0; i < this->edges.size(); i++) {
//            if (this->edges[i] != nullptr) {
//
//                this->edges[i]->clearVertices();
//                this->edges[i]->clearAdjEdges();
//                delete this->edges[i];
//            }
//        }
//    };
//
//    void Board::setResource(int resourceType) {
//        switch (resourceType) {
//            case 0:
//                this->resource = "BRICK";
//                break;
//            case 1:
//                this->resource = "WOOD";
//                break;
//            case 2:
//                this->resource = "WHEAT";
//                break;
//            case 3:
//                this->resource = "SHEEP";
//                break;
//            case 4:
//                this->resource = "STONE";
//                break;
//            case 5:
//                this->resource = "DESERT";
//                break;
//        }
//        this->setVerticesResource(resourceType);
//    }
//
//    void Board::setVerticesResource(int resourceType) {
//        for (size_t i = 0; i < this->vertices.size(); i++) {
//            this->vertices[i]->setResource(resourceType);
//        }
//    }
//
//    void Board::setVertices(Vertex *vertex0, Vertex *vertex1, Vertex *vertex2, Vertex *vertex3, Vertex *vertex4,
//                            Vertex *vertex5) {
//        this->vertices[0] = vertex0;
//        this->vertices[1] = vertex1;
//        this->vertices[2] = vertex2;
//        this->vertices[3] = vertex3;
//        this->vertices[4] = vertex4;
//        this->vertices[5] = vertex5;
//    }
//
//    void Board::setEdges(Edge *edge0, Edge *edge1, Edge *edge2, Edge *edge3, Edge *edge4, Edge *edge5) {
//        this->edges[0] = edge0;
//        this->edges[1] = edge1;
//        this->edges[2] = edge2;
//        this->edges[3] = edge3;
//        this->edges[4] = edge4;
//        this->edges[5] = edge5;
//    }
//
//    string Board::getLandSymbol() const {
//        if (this->resource == "WOOD") {
//            return "🌲";
//        } else if (this->resource == "BRICK") {
//            return "🧱";
//        } else if (this->resource == "SHEEP") {
//            return "🐑";
//        } else if (this->resource == "WHEAT") {
//            return "🌾";
//        } else if (this->resource == "STONE") {
//            return "⛰️ ";
//        } else if (this->resource == "DESERT") {
//            return "🏜️";
//        } else {
//            return " ";
//        }
//    }
//
//    size_t Board::getResourceNum() const {
//        if (this->resource == "BRICK") {
//            return 0;
//        } else if (this->resource == "WOOD") {
//            return 1;
//        } else if (this->resource == "WHEAT") {
//            return 2;
//        } else if (this->resource == "SHEEP") {
//            return 3;
//        } else if (this->resource == "STONE") {
//            return 4;
//        } else if (this->resource == "DESERT") {
//            return 5;
//        }
//        return 6;
//    }
//}


//namespace ariel {
//
//    Board::Board() {

        //this->_cBoard = vector<Hexagon>(19, null);

        // Random number
        //Hexagon h1 = new Hexagon(1, "");

//        vector<vector<string>> board(25, vector<string>(23, ""));
//        board[0][8] = "sea";
//        board[2][3] = "sea";
//        board[3][4] = "sea";
//        board[4][4] = "sea";
//        board[5][4] = "sea";
//        board[6][3] = "sea";
//        board[7][2] = "sea";
//        board[8][2] = "sea";
//        board[9][2] = "sea";
//        board[10][1] = "sea";
//        board[11][0] = "sea";
//        board[12][0] = "sea";
//        board[13][0] = "sea";
//        board[14][1] = "sea";
//        board[15][2] = "sea";
//        board[16][2] = "sea";
//        board[17][2] = "sea";
//        board[18][3] = "sea";
//        board[19][4] = "sea";
//        board[20][4] = "sea";
//        board[21][4] = "sea";
//        board[22][5] = "sea";
//        board[24][7] = "sea";
//
//        board[23][8] = "sea";
//        board[22][9] = "sea";
//        board[23][10] = "sea";
//        board[24][11] = "sea";
//        board[23][12] = "sea";
//        board[22][13] = "sea";
//        board[23][14] = "sea";
//        board[24][15] = "sea";
//        board[22][17] = "sea";
//        board[21][18] = "sea";
//
//        board[0][15] = "sea";
//        board[2][17] = "sea";
//        board[3][18] = "sea";
//        board[4][18] = "sea";
//        board[5][18] = "sea";
//        board[6][19] = "sea";
//        board[7][20] = "sea";
//        board[8][20] = "sea";
//        board[9][20] = "sea";
//        board[10][21] = "sea";
//        board[11][22] = "sea";
//        board[12][22] = "sea";
//        board[13][22] = "sea";
//        board[14][21] = "sea";
//        board[15][20] = "sea";
//        board[16][20] = "sea";
//        board[17][20] = "sea";
//        board[18][19] = "sea";
//        board[19][18] = "sea";
//        board[20][18] = "sea";
//
//        board[1][8] = "sea";
//        board[2][9] = "sea";
//        board[1][10] = "sea";
//        board[0][11] = "sea";
//        board[1][12] = "sea";
//        board[2][13] = "sea";
//        board[1][14] = "sea";
//
//        board[2][6] = "/";
//        board[4][5] = "|";
//        board[6][4] = "/";
//        board[8][3] = "|";
//        board[10][2] = "/";
//        board[12][1] = "/";
//        board[14][2] = "\\";
//        board[16][3] = "|";
//        board[18][4] = "\\";
//        board[20][5] = "|";
//        board[22][6] = "\\";
//        board[22][8] = "/";
//        board[22][10] = "\\";
//        board[22][12] = "/";
//        board[22][14] = "\\";
//        board[22][16] = "/";
//        board[20][17] = "|";
//        board[18][18] = "/";
//        board[16][19] = "|";
//        board[14][20] = "/";
//        board[12][21] = "|";
//        board[10][20] = "\\";
//        board[8][19] = "|";
//
//        board[6][18] = "\\";
//        board[4][17] = "|";
//        board[2][16] = "\\";
//        board[2][14] = "/";
//        board[2][12] = "\\";
//        board[2][10] = "/";
//        board[2][8] = "\\";
//
//        size_t i, j;
//
//        for(i = 0; i < 25; i++)
//        {
//            for(j = 0; j < 23; j++)
//            {
//                cout << board[i][j];
//            }
//            cout << endl;
//        }

//        board[0][8] = " sea ";
//        board[2][3] = " sea ";
//        board[3][4] = " sea ";
//        board[4][4] = " sea ";
//        board[5][4] = " sea ";
//        board[6][3] = " sea ";
//        board[7][2] = " sea ";
//        board[8][2] = " sea ";
//        board[9][2] = " sea ";
//        board[10][1] = " sea ";
//        board[11][0] = " sea ";
//        board[12][0] = " sea ";
//        board[13][0] = " sea ";
//        board[14][1] = " sea ";
//        board[15][2] = " sea ";
//        board[16][2] = " sea ";
//        board[17][2] = " sea ";
//        board[18][3] = " sea ";
//        board[19][4] = " sea ";
//        board[20][4] = " sea ";
//        board[21][4] = " sea ";
//        board[22][5] = " sea ";
//        board[24][7] = " sea ";
//
//        board[23][8] = " sea ";
//        board[22][9] = " sea ";
//        board[23][10] = " sea ";
//        board[24][11] = " sea ";
//        board[23][12] = " sea ";
//        board[22][13] = " sea ";
//        board[23][14] = " sea ";
//        board[24][15] = " sea ";
//        board[22][17] = " sea ";
//        board[21][18] = " sea ";
//
//        board[0][15] = " sea ";
//        board[2][17] = " sea ";
//        board[3][18] = " sea ";
//        board[4][18] = " sea ";
//        board[5][18] = " sea ";
//        board[6][19] = " sea ";
//        board[7][20] = " sea ";
//        board[8][20] = " sea ";
//        board[9][20] = " sea ";
//        board[10][21] = " sea ";
//        board[11][22] = " sea ";
//        board[12][22] = " sea ";
//        board[13][22] = " sea ";
//        board[14][21] = " sea ";
//        board[15][20] = " sea ";
//        board[16][20] = " sea ";
//        board[17][20] = " sea ";
//        board[18][19] = " sea ";
//        board[19][18] = " sea ";
//        board[20][18] = " sea ";
//
//        board[1][8] = " sea ";
//        board[2][9] = " sea ";
//        board[1][10] = " sea ";
//        board[0][11] = " sea ";
//        board[1][12] = " sea ";
//        board[2][13] = " sea ";
//        board[1][14] = " sea ";

//        vector <vector<string>> gameBoard(9, vector<string>(10, "   "));
//
//        //size_t i, j;
//
//        for (i = 0; i < 4; i++)
//            gameBoard[0][i] = "***";
//
//        for (i = 6; i < 10; i++)
//            gameBoard[0][i] = "***";
//
//        gameBoard[0][4] = "CATAN";
//        gameBoard[0][5] = "BOARD";
//
//        for (i = 3; i < 7; i++) {
//            gameBoard[1][i] = "sea";
//            gameBoard[7][i] = "sea";
//        }
//
//
//        gameBoard[2][2] = "sea";
//        gameBoard[2][7] = "sea";
//        gameBoard[3][1] = "sea";
//        gameBoard[3][8] = "sea";
//        gameBoard[4][0] = "sea";
//        gameBoard[4][9] = "sea";
//        gameBoard[5][1] = "sea";
//        gameBoard[5][8] = "sea";
//        gameBoard[6][2] = "sea";
//        gameBoard[6][7] = "sea";
//
//
//        for (i = 0; i < 9; i++) {
//            for (j = 0; j < 10; j++) {
//                if (i == 0 && j != 3 && j != 4 && j != 5)
//                    cout << gameBoard[i][j];
//                else
//                    cout << gameBoard[i][j] << " ";
//            }
//            cout << endl;
//        }
//
//
//        this->_CatanBoard = gameBoard;
//
//        vector <vector<size_t>> placenum(9, vector<size_t>(10, 0));
//        vector <size_t> numbers_left(13, 0);
//
//        numbers_left[2] = 1;
//        numbers_left[3] = 2;
//        numbers_left[4] = 2;
//        numbers_left[5] = 2;
//        numbers_left[6] = 2;
//        numbers_left[8] = 2;
//        numbers_left[9] = 2;
//        numbers_left[10] = 2;
//        numbers_left[11] = 2;
//        numbers_left[12] = 1;




//    }
//}
