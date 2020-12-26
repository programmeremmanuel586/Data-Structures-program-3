//
//  Battle.hpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/26/20.
//

#pragma once
#ifndef Battle_h
#define Battle_h

#include <iostream>
#include <string>
#include "Actor.h"
#include "enum.hpp"
#include "ActorFactory.h"
#include "CommandManager.h"

class Battle {
private:
    CommandManager mgr;
    Actor* player1;     // User
    Actor* player2;     // Computer

public:
    // Constructor
    Battle(ActorType actor1, ActorType actor2);

    // Default Constructor
    Battle();

    // Destructor
    ~Battle();

    // Methods
    void Game();
    void Start();
    bool PlayerTurn();
    void NpcTurn();     // Computer Turn
};

#endif /* Battle_h */
