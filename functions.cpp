//
//  functions.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/27/20.
//

#include <iostream>
#include <string>
#include "enum.hpp"
#include "functions.h"

int RandNumGenerator(int min, int max) {
    srand(static_cast<int>(time(nullptr)));
    return rand() % (max - min + 1) + min;
}

std::string actorDisplayName(ActorType actortype) {
    std::string actor;
    switch (actortype) {
        case ActorType::Ghost:
            actor = "Ghost";
            break;
        case ActorType::Knight:
            actor = "Knight";
            break;
    }
    return actor;
}

std::string moveDisplayName(MoveType movetype) {
    std::string move;
    switch (movetype) {
        case MoveType::Curse:
            move = "Curse";
            break;
        case MoveType::Sword:
            move = "Sword";
            break;
        case MoveType::Spell:
            move = "Spell";
            break;
        case MoveType::Melee:
            move = "Melee";
            break;
    }
    return move;
}
