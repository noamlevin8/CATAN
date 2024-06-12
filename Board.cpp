// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Board.hpp"

namespace ariel {

    Board::Board() {

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




    }
}