// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"

#include <sstream>

using namespace std;
using namespace ariel;

int main()
{
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);  // should print the name of the starting player, assume it is Amit.

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    catan.getBoard()->printBoard(); // The start of the game
    cout << player->getName() << "'s turn!" << endl;

    player->placeRoad(44, 40, *catan.getBoard()); // Amit builds a road

    player = catan.endTurn(); // Yossi's turn

    player->addBrick(2);
    player->addWheat(1);
    player->addWood(1);

    player->placeRoad(24, 30, *catan.getBoard()); // Yossi builds a road
    player->placeSettlement(30, *catan.getBoard()); // Yossi builds a settlement on 30

    player = catan.endTurn(); // Dana's turn

    player->addWheat(3);
    player->addStone(4);

    player->placeCity(47, *catan.getBoard()); // Dana builds a city on 47

    catan.buyDevelopmentCard(*player); // Dana buys a "Build 2 Roads" card

    player = catan.endTurn(); // Amit's turn

    player->addWood(6);

    // Amit trades with Dana (2 wood for 1 brick) and trades bank (wood for stone)
    player->trade(*catan.getPlayer(3), "wood", "brick", 2, 1);
    player->tradeBank("wood", "stone");

    player = catan.endTurn(); // Yossi's turn

    player->addWheat(6);
    player->addStone(6);
    player->addSheep(6);

    for(int i = 0; i < 6; i++){
        // Yossi buys 3 "Knight", 1 "Victory Point", 1 "Year of Plenty", 1 "Monopoly"
        catan.buyDevelopmentCard(*player);
    }

    // Yossi uses a "Monopoly" card and takes brick from the others
    orig = cin.rdbuf();
    istringstream input1("\nMonopoly\nbrick\n");
    cin.rdbuf(input1.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    // Yossi uses a "Year of Plenty" card and takes wood and sheep from the bank
    orig = cin.rdbuf();
    istringstream input2("\nYear of Plenty\nwood\nsheep\n");
    cin.rdbuf(input2.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    // Yossi uses the "Knight" cards and gets 2 points
    orig = cin.rdbuf();
    istringstream input3("\nKnight\n");
    cin.rdbuf(input3.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    orig = cin.rdbuf();
    istringstream input4("\nKnight\n");
    cin.rdbuf(input4.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    orig = cin.rdbuf();
    istringstream input5("\nKnight\n");
    cin.rdbuf(input5.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    player = catan.endTurn(); // Dana's turn

    // Dana uses a "Build 2 Roads" card and builds 2 roads
    orig = cin.rdbuf();
    istringstream input6("\nBuild 2 Roads\n42\n37\n32\n38\n");
    cin.rdbuf(input6.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    player = catan.endTurn(); // Amit's turn

    player = catan.endTurn(); // Yossi's turn

    player->addVictoryPoint(3); // Adding Yossi 3 points (has 9)
    catan.hasWinner(); // Should be no

    player->addVictoryPoint(1); // Adding Yossi a point (has 10)
    catan.hasWinner(); // Should be Yes

    catan.getBoard()->printBoard(); // Printing the board at the end of the game
    player->printPoints(); // Printing Yossi's points
    catan.printWinner(); // Printing that Yossi is the winner

    return 0;
}