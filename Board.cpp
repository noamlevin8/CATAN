// ID: 326662574 
// MAIL: noamlevin11@gmail.com

#include "Board.hpp"

using namespace ariel;

Board::Board()
{
    vector<vector<string>> gameBoard(9, vector<string>(10, "   "));
    
    size_t i, j;

    for(i = 0; i < 4; i++)
        gameBoard[0][i] = "***";

    for(i = 6; i < 10; i++)
        gameBoard[0][i] = "***";

    gameBoard[0][4] = "CATAN";
    gameBoard[0][5] = "BOARD";

    for(i = 3; i < 7; i++)
    {
        gameBoard[1][i] = "sea";
        gameBoard[7][i] = "sea";
    }


    gameBoard[2][2] = "sea";
    gameBoard[2][7] = "sea";
    gameBoard[3][1] = "sea";
    gameBoard[3][8] = "sea";
    gameBoard[4][0] = "sea";
    gameBoard[4][9] = "sea";
    gameBoard[5][1] = "sea";
    gameBoard[5][8] = "sea";
    gameBoard[6][2] = "sea";
    gameBoard[6][7] = "sea";


    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(i == 0 && j != 3 && j != 4 && j != 5)
                cout << gameBoard[i][j];
            else
                cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }


    this->_CatanBoard = gameBoard;
}