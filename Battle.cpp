//
//  Battle.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/16/20.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Actor.h"
#include "ActorFactory.h"
#include "Battle.h"
#include "BattleMove.h"
#include "BattleMoveFactory.h"
#include "functions.h"


Battle::Battle(ActorType actor1, ActorType actor2) {
    player1 = ActorFactory::CreateActor(actor1);
    player2 = ActorFactory::CreateActor(actor2);
}

Battle::Battle() {}
Battle::~Battle() {}


// Game menu and setup (And to start the game)
void Battle::Game() {

    int userChoice;

    // Menu
    std::cout << "\nWelcome to the Battle Game!\n";
    std::cout << "Choose one of the following:\n1) Battle!\n2) Quit\n";
    std::cout << "> ";
    std::cin >> userChoice;


    // Input Checker
    while (userChoice != 1 && userChoice != 2) {
        std::cout << "Enter a 1 to start game or a 2 to quit\n";
        std::cout << "> ";
        std::cin >> userChoice;
    }

    if (userChoice == 2) {
        std::cout << "Exiting Game..." << std::endl;
        std::cout << "Game Exited" << std::endl;
        exit(EXIT_SUCCESS);
    }

    // Choose your Character (lists the names of the enum type in string using function)
    std::cout << "\nChoose your character:\n";
    for (int character = Ghost; character <= Knight; character++) {
        ActorType a = static_cast<ActorType>(character);
        std::cout << (character + 1) << ") " << actorDisplayName(a) << std::endl;
    }
    std::cout << "> ";
    std::cin >> userChoice;

    // Input Checker
    while (userChoice != 1 && userChoice != 2) {
        std::cout << "Enter a 1 for a Ghost character or a 2 for a Knight character\n";
        std::cout << "> ";
        std::cin >> userChoice;
    }


    // Player 1 character
    if (userChoice == 1) {
        player1 = ActorFactory::CreateActor(ActorType::Ghost);
        player1->SetType("Ghost");
        std::cout << "Your player: " << actorDisplayName(ActorType::Ghost) << std::endl;
    }
    if (userChoice == 2) {
        player1 = ActorFactory::CreateActor(ActorType::Knight);
        player1->SetType("Knight");
        std::cout << "Your player: " << actorDisplayName(ActorType::Knight) << std::endl;
    }

    // Choose opponent Character
    std::cout << "\nChoose your opponent's character:\n";
    for (int character = Ghost; character <= Knight; character++) {
        ActorType a = static_cast<ActorType>(character);
        std::cout << (character + 1) << ") " << actorDisplayName(a) << std::endl;
    }
    std::cout << "> ";
    std::cin >> userChoice;

    // Input Checker
    while (userChoice != 1 && userChoice != 2) {
        std::cout << "Enter a 1 for a Ghost character or a 2 for a Knight character\n";
        std::cout << "> ";
        std::cin >> userChoice;
    }

    // Player 2 character
    if (userChoice == 1) {
        player2 = ActorFactory::CreateActor(ActorType::Ghost);
        player2->SetType("Ghost");
        std::cout << "Your opponent's player: " << actorDisplayName(ActorType::Ghost) << std::endl;
    }
    if (userChoice == 2) {
        player2 = ActorFactory::CreateActor(ActorType::Knight);
        player2->SetType("Knight");
        std::cout << "Your opponent's player: " << actorDisplayName(ActorType::Knight) << std::endl;
    }

    // Start Battle
    Start();

}

// Starts loop for game
void Battle::Start() {
    // user input
    int userChoice;

    std::cout << std::endl;
    std::cout << "--------------------Starting Battle----------------------" << std::endl;

    while (!player1->IsDead() && !player2->IsDead()) {

        std::cout << "\n" << *player1 << ", " << *player2 << std::endl;

        // User move
        std::cout << "Your turn" << std::endl;
        std::cout << "Choose your move:" << std::endl;
        int num = 1;
        for (auto i: player1->GetMoves()) {
            std::cout << num << ") " << moveDisplayName(i) << std::endl;
            num += 1;
        }
        std::cout << "3) Undo" << std::endl;
        std::cout << "> ";
        std::cin >> userChoice;

        // Input Checker (Works for both Ghost and Knight characters) :)
        while (userChoice != 1 && userChoice != 2 && userChoice != 3) {
            std::cout << "Your input was invalid. Enter one of the following options below\n";
            num = 1;
            for (auto i: player1->GetMoves()) {
                std::cout << num << ") " << moveDisplayName(i) << std::endl;
                num += 1;
            }
            std::cout << "3) Undo" << std::endl;
            std::cout << "> ";
            std::cin >> userChoice;
        }

        // Player 1 Battle Move choice
        if (userChoice == 1 || userChoice == 2) {
            auto attack = BattleMoveFactory::BuildMove(player1->GetMoves()[userChoice - 1], player1, player2);
            std::cout << moveDisplayName((player1->GetMoves()[userChoice - 1])) << " Attack!" << std::endl;
            mgr.Execute(attack);
        }
        if (userChoice == 3) {
            // Undo the last two moves
            mgr.Undo();
            mgr.Undo();
            continue;
        }

        // Computer Move
        NpcTurn();

    }

    if (player1->IsDead()) {
        std::cout << "\n" << *player2 << " defeated " << *player1 << " in battle!\n";
    } else if (player2->IsDead()) {
        std::cout << "\n" << *player1 << " defeated " << *player2 << " in battle!\n";
    }


}

void Battle::NpcTurn() {
    // Randomly generated number for computer
    int computerChoice = RandNumGenerator(1, 2);

    std::cout << "Enemy's turn" << std::endl;

    // Displays Battle Move according to selected number in movetype vector from actor class
    if (computerChoice == 1 || computerChoice == 2) {
        auto attack = BattleMoveFactory::BuildMove(player2->GetMoves()[computerChoice - 1], player2, player1);
        std::cout << moveDisplayName((player2->GetMoves()[computerChoice - 1])) << " Attack!" << std::endl;
        // attack->Execute();
        mgr.Execute(attack);
    }
}
