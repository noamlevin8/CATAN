//ID: 326662574
//MAIL: noamlevin11@gmail.com

#include "doctest.h"
#include "Catan.hpp"

#include <sstream>

using namespace ariel;
using namespace std;

streambuf* orig = cout.rdbuf();

void suppressOutput()
{
    cout.rdbuf(NULL);
}

void restoreOutput()
{
    cout.rdbuf(orig);
}

TEST_CASE("Test resources and settlements after first round")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    restoreOutput();
    // Checking resources
    CHECK(player->getNumOfBrick() == 1);
    CHECK(player->getNumOfWood() == 1);

    // Checking settlements
    CHECK(catan.getBoard()->getPlace(48)->getOwner() == player->getColor());
    CHECK(catan.getBoard()->getPlace(49)->getOwner() == player->getColor());

    suppressOutput();
    player = catan.endTurn();

    restoreOutput();
    // Checking resources
    CHECK(player->getNumOfSheep() == 1);
    CHECK(player->getNumOfWood() == 1);

    // Checking settlements
    CHECK(catan.getBoard()->getPlace(19)->getOwner() == player->getColor());
    CHECK(catan.getBoard()->getPlace(29)->getOwner() == player->getColor());

    suppressOutput();
    player = catan.endTurn();

    restoreOutput();
    // Checking resources
    CHECK(player->getNumOfSheep() == 1);
    CHECK(player->getNumOfBrick() == 1);

    // Checking settlements
    CHECK(catan.getBoard()->getPlace(47)->getOwner() == player->getColor());
    CHECK(catan.getBoard()->getPlace(37)->getOwner() == player->getColor());

}

TEST_CASE("Building a road")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    restoreOutput();
    CHECK(player->placeRoad(46, 50, *catan.getBoard()) == false); // Not a valid place for this player
    CHECK(player->placeRoad(44, 40, *catan.getBoard()) == true); // Valid place

    // Checking that the player really paid
    CHECK(player->getNumOfWood() == 0);
    CHECK(player->getNumOfBrick() == 0);
}

TEST_CASE("Building a settlement")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    player->placeRoad(44, 40, *catan.getBoard());

    player = catan.endTurn();

    player->addBrick(1);
    player->addWheat(1);
    player->addWood(1);

    player->placeRoad(24, 30, *catan.getBoard()); // Building a road
    player->placeSettlement(30, *catan.getBoard()); // Trying to build a settlement

    restoreOutput();
    CHECK(catan.getBoard()->getPlace(30)->getOwner() != player->getColor()); // Not enough resources

    suppressOutput();
    player->addBrick(1);
    player->placeSettlement(30, *catan.getBoard()); // Now enough

    restoreOutput();
    CHECK(catan.getBoard()->getPlace(30)->getOwner() == player->getColor());
}

TEST_CASE("Building a city")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    player->placeRoad(44, 40, *catan.getBoard());

    player = catan.endTurn();

    player->addBrick(2);
    player->addWheat(1);
    player->addWood(1);

    player->placeRoad(24, 30, *catan.getBoard()); // Building a road
    player->placeSettlement(30, *catan.getBoard()); // Building a settlement

    player = catan.endTurn();

    player->addWheat(1);
    player->addStone(4);

    string c = player->getColor();

    player->placeCity(47, *catan.getBoard()); // Trying to build a city

    restoreOutput();
    CHECK(catan.getBoard()->getPlace(47)->getOwner() != c.replace(2, 2, "1;"));

    suppressOutput();
    player->addWheat(2);
    player->placeCity(47, *catan.getBoard()); // Build a city

    restoreOutput();
    CHECK(catan.getBoard()->getPlace(47)->getOwner() == c.replace(2, 2, "1;"));
}

TEST_CASE("Trades")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    player->placeRoad(44, 40, *catan.getBoard());

    player = catan.endTurn();

    player->addBrick(2);
    player->addWheat(1);
    player->addWood(1);

    player->placeRoad(24, 30, *catan.getBoard());
    player->placeSettlement(30, *catan.getBoard());

    player = catan.endTurn();

    player->addWheat(3);
    player->addStone(4);

    player->placeCity(47, *catan.getBoard());

    catan.buyDevelopmentCard(*player);

    player = catan.endTurn();

    player->addWood(6);

    player->trade(*catan.getPlayer(3), "wood", "brick", 2, 2); // Didn't work

    restoreOutput();
    CHECK(player->getNumOfBrick() == 0);
    CHECK(player->getNumOfWood() == 6);

    suppressOutput();
    player->trade(*catan.getPlayer(3), "wood", "brick", 2, 1); // Now worked

    restoreOutput();
    CHECK(player->getNumOfBrick() == 1);
    CHECK(player->getNumOfWood() == 4);

    suppressOutput();
    player->tradeBank("wood", "stone");

    restoreOutput();
    CHECK(player->getNumOfWood() == 0);
    CHECK(player->getNumOfStone() == 1);
}

TEST_CASE("Card")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    player->placeRoad(44, 40, *catan.getBoard());

    player = catan.endTurn();

    player->addBrick(2);
    player->addWheat(1);
    player->addWood(1);

    player->placeRoad(24, 30, *catan.getBoard());
    player->placeSettlement(30, *catan.getBoard());

    player = catan.endTurn();

    player->addWheat(3);
    player->addStone(4);

    player->placeCity(47, *catan.getBoard());

    catan.buyDevelopmentCard(*player);

    player = catan.endTurn();

    player->addWood(6);

    player->trade(*catan.getPlayer(3), "wood", "brick", 2, 1);
    player->tradeBank("wood", "stone");

    player = catan.endTurn();

    player->addWheat(6);
    player->addStone(6);
    player->addSheep(6);

    for(int i = 0; i < 6; i++){
        catan.buyDevelopmentCard(*player);
    }

    restoreOutput();
    CHECK(player->getNumOfWheat() == 0);
    CHECK(player->getNumOfStone() == 0);
    CHECK(player->getNumOfSheep() == 0);

    suppressOutput();
    orig = cin.rdbuf();
    istringstream input1("\nMonopoly\nbrick\n");
    cin.rdbuf(input1.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    // Checking that we took from the others
    player = catan.endTurn();

    restoreOutput();
    CHECK(player->getNumOfBrick() == 0);

    suppressOutput();
    player = catan.endTurn();

    restoreOutput();
    CHECK(player->getNumOfBrick() == 0);

    suppressOutput();
    player = catan.endTurn();

    orig = cin.rdbuf();
    istringstream input2("\nYear of Plenty\nwood\nsheep\n");
    cin.rdbuf(input2.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    restoreOutput();
    CHECK(player->getNumOfWood() == 1);
    CHECK(player->getNumOfSheep() == 1);

    suppressOutput();
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

    restoreOutput();
    CHECK(player->getPoints() == 6);

    suppressOutput();
    player = catan.endTurn();

    restoreOutput();
    CHECK(player->getNumOfBuild2Roads() == 1);

    suppressOutput();
    orig = cin.rdbuf();
    istringstream input6("\nBuild 2 Roads\n42\n37\n32\n38\n");
    cin.rdbuf(input6.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    restoreOutput();
    CHECK(player->getNumOfBuild2Roads() == 0);
}

TEST_CASE("Winner")
{
    suppressOutput();
    Player p1("Amit", "\033[0;34m"); // Blue color
    Player p2("Yossi", "\033[0;31m"); // Red color
    Player p3("Dana", "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3, true);

    Player *player = catan.ChooseStartingPlayer(true);

    // Settlement assignment for the start of the game
    streambuf* orig = cin.rdbuf();
    istringstream input("48\n44\n29\n23\n37\n32\n47\n42\n19\n24\n49\n45\n");
    cin.rdbuf(input.rdbuf());
    catan.firstTurn(*player);
    cin.rdbuf(orig);

    player->placeRoad(44, 40, *catan.getBoard());

    player = catan.endTurn();

    player->addBrick(2);
    player->addWheat(1);
    player->addWood(1);

    player->placeRoad(24, 30, *catan.getBoard());
    player->placeSettlement(30, *catan.getBoard());

    player = catan.endTurn();

    player->addWheat(3);
    player->addStone(4);

    player->placeCity(47, *catan.getBoard());

    catan.buyDevelopmentCard(*player);

    player = catan.endTurn();

    player->addWood(6);

    player->trade(*catan.getPlayer(3), "wood", "brick", 2, 1);
    player->tradeBank("wood", "stone");

    player = catan.endTurn();

    player->addWheat(6);
    player->addStone(6);
    player->addSheep(6);

    for(int i = 0; i < 6; i++){
        catan.buyDevelopmentCard(*player);
    }

    orig = cin.rdbuf();
    istringstream input1("\nMonopoly\nbrick\n");
    cin.rdbuf(input1.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    orig = cin.rdbuf();
    istringstream input2("\nYear of Plenty\nwood\nsheep\n");
    cin.rdbuf(input2.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

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

    player = catan.endTurn();

    orig = cin.rdbuf();
    istringstream input6("\nBuild 2 Roads\n42\n37\n32\n38\n");
    cin.rdbuf(input6.rdbuf());
    catan.useDevelopmentCard(*player);
    cin.rdbuf(orig);

    player = catan.endTurn();
    player = catan.endTurn();

    player->addVictoryPoint(3);

    restoreOutput();
    CHECK(catan.hasWinner() == false); // Should be no

    suppressOutput();
    player->addVictoryPoint(1);

    restoreOutput();
    CHECK(catan.hasWinner() == true); // Should be Yes
}
