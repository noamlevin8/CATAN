// ID: 326662574
// MAIL: noamlevin11@gmail.com

#include "Card.hpp"
#include "Catan.hpp"

namespace ariel{

    Card::~Card() {}

    // The way each type uses itself
    Monopoly::Monopoly() : Card("Monopoly") {}
    void Monopoly::use_card(Player &p, Catan &c) {
        string choice;
        bool check = false;
        int sum = 0;

        while (!check){
            cout << "What do you want to get?" << endl;
            cin >> choice;

            if(choice == "wood"){
                if(c.getPlayer(1)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(1)->getNumOfWood();
                    c.getPlayer(1)->subWood(c.getPlayer(1)->getNumOfWood());
                }
                if(c.getPlayer(2)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(2)->getNumOfWood();
                    c.getPlayer(2)->subWood(c.getPlayer(2)->getNumOfWood());
                }
                if(c.getPlayer(3)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(3)->getNumOfWood();
                    c.getPlayer(3)->subWood(c.getPlayer(3)->getNumOfWood());
                }

                p.addWood(sum);
                check = true;

            } else if(choice == "brick"){
                if(c.getPlayer(1)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(1)->getNumOfBrick();
                    c.getPlayer(1)->subBrick(c.getPlayer(1)->getNumOfBrick());
                }
                if(c.getPlayer(2)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(2)->getNumOfBrick();
                    c.getPlayer(2)->subBrick(c.getPlayer(2)->getNumOfBrick());
                }
                if(c.getPlayer(3)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(3)->getNumOfBrick();
                    c.getPlayer(3)->subBrick(c.getPlayer(3)->getNumOfBrick());
                }

                p.addBrick(sum);
                check = true;

            } else if(choice == "sheep"){
                if(c.getPlayer(1)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(1)->getNumOfSheep();
                    c.getPlayer(1)->subSheep(c.getPlayer(1)->getNumOfSheep());
                }
                if(c.getPlayer(2)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(2)->getNumOfSheep();
                    c.getPlayer(2)->subSheep(c.getPlayer(2)->getNumOfSheep());
                }
                if(c.getPlayer(3)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(3)->getNumOfSheep();
                    c.getPlayer(3)->subSheep(c.getPlayer(3)->getNumOfSheep());
                }

                p.addSheep(sum);
                check = true;

            } else if(choice == "stone"){
                if(c.getPlayer(1)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(1)->getNumOfStone();
                    c.getPlayer(1)->subStone(c.getPlayer(1)->getNumOfStone());
                }
                if(c.getPlayer(2)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(2)->getNumOfStone();
                    c.getPlayer(2)->subStone(c.getPlayer(2)->getNumOfStone());
                }
                if(c.getPlayer(3)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(3)->getNumOfStone();
                    c.getPlayer(3)->subStone(c.getPlayer(3)->getNumOfStone());
                }

                p.addStone(sum);
                check = true;

            } else if(choice == "wheat"){
                if(c.getPlayer(1)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(1)->getNumOfWheat();
                    c.getPlayer(1)->subWheat(c.getPlayer(1)->getNumOfWheat());
                }
                if(c.getPlayer(2)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(2)->getNumOfWheat();
                    c.getPlayer(2)->subWheat(c.getPlayer(2)->getNumOfWheat());
                }
                if(c.getPlayer(3)->getIdx() != p.getIdx()){
                    sum += c.getPlayer(3)->getNumOfWheat();
                    c.getPlayer(3)->subWheat(c.getPlayer(3)->getNumOfWheat());
                }

                p.addWheat(sum);
                check = true;

            } else
                cout << "Not a valid resource. Try again." << endl;
        }

        p.subMonopoly(1);
    }

    Build2Roads::Build2Roads() : Card("Build 2 Roads") {}
    void Build2Roads::use_card(Player &p, Catan &c) {
        p.addWood(2);
        p.addBrick(2);

        bool check = false;
        unsigned int from, to;

        cout << "First road" << endl;
        while (!check) {
            cout << "From: " << endl;
            cin >> from;
            cout << "To: " << endl;
            cin >> to;

            if(p.placeRoad(from, to, *c.getBoard()))
                check = true;
            else
                cout << "Try again!" << endl;
        }

        check = false;

        cout << "Second road" << endl;
        while (!check){
            cout << "From: " << endl;
            cin >> from;
            cout << "To: " << endl;
            cin >> to;

            if(p.placeRoad(from, to, *c.getBoard()))
                check = true;
            else
                cout << "Try again!" << endl;
        }

        p.sub2Roads(1);
    }

    YearOfPlenty::YearOfPlenty() : Card("Year of Plenty") {}
    void YearOfPlenty::use_card(Player &p, Catan &c) {
        string choice;
        bool check = false;

        while (!check) {
            cout << "Choose the first resource to get: " << endl;
            cin >> choice;

            if (choice == "wood") {
                p.addWood(1);
                check = true;
            }
            else if (choice == "brick") {
                p.addBrick(1);
                check = true;
            }
            else if (choice == "sheep") {
                p.addSheep(1);
                check = true;
            }
            else if (choice == "stone") {
                p.addStone(1);
                check = true;
            }
            else if (choice == "wheat") {
                p.addWheat(1);
                check = true;
            }
            else
                cout << "Not a valid type. Try again." << endl;
        }

        check = false;

        while (!check) {
            cout << "Choose the second resource to get: " << endl;
            cin >> choice;

            if (choice == "wood") {
                p.addWood(1);
                check = true;
            }
            else if (choice == "brick") {
                p.addBrick(1);
                check = true;
            }
            else if (choice == "sheep") {
                p.addSheep(1);
                check = true;
            }
            else if (choice == "stone") {
                p.addStone(1);
                check = true;
            }
            else if (choice == "wheat") {
                p.addWheat(1);
                check = true;
            }
            else
                cout << "Not a valid type. Try again." << endl;
        }

        p.subYearOfPlenty(1);
    }

    Knight::Knight() : Card("Knight") {}
    void Knight::use_card(Player &p, Catan &c) {
        cout << "Added a Knight" << endl;

        p.useKnight();

        if(p.getNumUsedKnights() == 3)
            p.KnightsPoints();
    }

    VictoryPoint::VictoryPoint() : Card("Victory Point") {}
    void VictoryPoint::use_card(Player &p, Catan &c) {
        cout << "Added a Victory Point" << endl;
    }
}
