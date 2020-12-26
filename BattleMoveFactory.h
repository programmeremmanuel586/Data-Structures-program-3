//
//  BattleMoveFactory.hpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/29/20.
//

#pragma once
#ifndef BattleMoveFactory_h
#define BattleMoveFactory_h

#include "BattleMove.h"
#include "Actor.h"
#include "enum.hpp"

class BattleMoveFactory {
public:
    // Battle Move maker
    static BattleMove* BuildMove(MoveType moveType, Actor* attacker, Actor* target);
};

#endif /* BattleMoveFactory_h */
