// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include <iostream>
#include <stdexcept>

#include "Catan.hpp"
#include "Player.hpp"

using namespace ariel;
using namespace std;

int main() {
    string name1, name2, name3;

    cout << "Welcome to a Catan Game!\n Please insert your names" << endl;
    cout << "Player 1 (You're Blue):" << endl;
    cin >> name1;
    cout << "Player 2 (You're Red):" << endl;
    cin >> name2;
    cout << "Player 3 (You're Green):" << endl;
    cin >> name3;

    // Creating the players for the game
    Player p1(name1, "\033[0;34m"); // Blue color
    Player p2(name2, "\033[0;31m"); // Red color
    Player p3(name3, "\033[0;32m"); // Green color

    Catan catan(p1, p2, p3); // Creating the game

    Player player = catan.ChooseStartingPlayer(); // Prints the name of the first player

//
////    Board board = catan.getBoard(); // Get the board of the game
//
//    // Settlement assignment for the start of the game (need to create a function)
//
//
//    catan.getBoard().printBoard(); // The start of the game
//    cout << player.getName() << "'s turn!" << endl;
//
//    int dice, menu;
//
//
//    while (!catan.hasWinner()) {
//        dice = player.rollDice();
//        catan.updateResources(dice);
//
//        menu = 10;
//
//        while (menu != 9) {
//            cout << "==============================" << endl;
//            cout << "Your resources: " << endl;
//            cout << "Wood: " << player.getNumOfWood() << endl;
//            cout << "Brick: " << player.getNumOfBrick() << endl;
//            cout << "Sheep: " << player.getNumOfSheep() << endl;
//            cout << "Stone: " << player.getNumOfStone() << endl;
//            cout << "Wheat: " << player.getNumOfWheat() << endl;
//            cout << "------------------------------" << endl;
//            cout << "Your cards: " << endl;
//            cout << "Monopoly: " << player.getNumOfMonopoly() << endl;
//            cout << "Build 2 Roads: " << player.getNumOfBuild2Roads() << endl;
//            cout << "Year of Plenty: " << player.getNumOfYearOfPlenty() << endl;
//            cout << "Knight: " << player.getNumOfKnights() << endl;
//            cout << "Victory Point: " << player.getNumOfVictoryPoints() << endl;
//            cout << "==============================" << endl;
//            cout << "Choose your move:" << endl;
//            cout << "1 - Build road" << endl;
//            cout << "2 - Build settlement" << endl;
//            cout << "3 - Upgrade to city" << endl;
//            cout << "4 - Trade resources with another player" << endl;
//            cout << "5 - Trade cards with another player" << endl;
//            cout << "6 - Trade with bank" << endl; // 4 resources from the same type (need to implement)
//            cout << "7 - Buy development card" << endl;
//            cout << "8 - Use development card" << endl;
//            cout << "9 - - End turn" << endl;
//            cout << "0 - Exit game" << endl;
//
//            cin >> menu;
//
//            switch (menu) {
//                case 1:
//                    cout << "Where do you want to build the road? (0 to change move)" << endl;
//
//                    unsigned int from, to;
//                    cout << "From: " << end;
//                    cin >> from;
//
//                    if(from == 0)
//                        break;
//
//                    cout << "To: " << end;
//                    cin >> to;
//
//                    player.placeRoad(from, to, catan.getBoard());
//
//                    break;
//                case 2:
//                    cout << "Where do you want to build the settlement? (0 to change move)" << endl;
//
//                    unsigned int place;
//                    cin >> place;
//
//                    if(place == 0)
//                        break;
//
//                    player.placeSettlement(place, catan.getBoard());
//
//                    break;
//                case 3:
//                    cout << "Choose settlement's place to upgrade it. (0 to change move)" << endl;
//
//                    unsigned int place;
//                    cin >> place;
//
//                    if(place == 0)
//                        break;
//
//                    player.placeCity(place, catan.getBoard());
//
//                    break;
//                case 4:
//                    cout << "Who do you wanna trade with? (0 to change move)" << endl;
//
//                    string name;
//
//                    cin >> name;
//
//                    if(name == "0")
//                        break;
//
//                    if(player.getName() == name) {
//                        cout << "Can't make a trade with yourself" << endl;
//                        break;
//                    }
//
//                    Player pForTrade;
//
//                    if(catan.getPlayer(1).getName() == name)
//                        pForTrade = catan.getPlayer(1);
//
//                    else if(catan.getPlayer(2).getName() == name)
//                        pForTrade = catan.getPlayer(2);
//
//                    else if(catan.getPlayer(3).getName() == name)
//                        pForTrade = catan.getPlayer(3);
//
//                    else{
//                        cout << "Not a valid name!" << endl;
//                        break;
//                    }
//
//                    cout << "What do you want to get and how many?" << endl;
//
//                    string get, give;
//                    int getNum, giveNum;
//
//                    cout << "What: " << endl;
//                    cin >> get;
//
//                    cout << "How many: " << endl;
//                    cin >> getNum;
//
//                    cout << "What do you want to give and how many?" << endl;
//
//                    cout << "What: " << endl;
//                    cin >> give;
//
//                    cout << "How many: " << endl;
//                    cin >> giveNum;
//
//                    player.trade(pForTrade, give, get, giveNum, getNum);
//
//                    break;
//                case 5:
//                    // Trade cards (needs implementation)
//                    break;
//                case 6:
//                    // Trade with bank (needs implementation)
//                    break;
//                case 7:
//                    player.buyDevelopmentCard(); // (need to actually buy the card)
//
//                    break;
//                case 8:
//                    cout << "Select card to use (0 to change move):" << endl;
//
//                    string type;
//                    cin >> type;
//
//                    if(type == 0)
//                        break;
//
//                    player.useCard(catan.getBoard(), type);
//
//                    break;
//                case 9:
//                    player = catan.endTurn();
//                    break;
//                case 0:
//                    cout << "Exiting game." << endl;
//                    return 0; // Exit the game loop and end the program
//                default:
//                    cout << "Invalid choice. Please choose a valid option." << endl;
//                    break;
//            }
//            catan.getBoard().printBoard();
//        }
//    }
//    catan.printWinner();

//    Board board = Board();
//    board.printBoard();

    catan.getBoard().printBoard();
    return 0;
}








//    Board board = Board();
//    board.printBoard();
//    return 0;
//}