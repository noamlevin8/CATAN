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
        vector<string> types = {"Wood", "Wood", "Wood", "Wood",
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

    // For the demo and tests (without shuffling)
    Board::Board(bool test){
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

        vector<unsigned int> nums = {5, 2, 6, 10, 9, 4, 3, 8, 11, 5, 8, 4, 3, 6, 10, 11, 12, 9};
        vector<string> types = {"Wood", "Stone", "Wheat", "Brick",
                                "Wheat", "Sheep", "Brick", "Wood",
                                "Brick", "Wheat", "Stone", "Brick",
                                "Wood", "Sheep", "Wheat",
                                "Wood", "Stone", "Sheep"};

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

    // Building the roads
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