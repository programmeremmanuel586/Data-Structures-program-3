//
//  BattleMoveFactory.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/16/20.
//

#include <iostream>
#include "enum.hpp"
#include "Actor.h"
#include "BattleMove.h"
#include "BattleMoveFactory.h"

BattleMove* BattleMoveFactory::BuildMove(MoveType moveType, Actor* attacker, Actor* target) {
    BattleMove* battleMove = nullptr;
    switch (moveType) {
        case MoveType::Curse:
            battleMove = new CurseAttack(attacker, target);
            break;
        case MoveType::Sword:
            battleMove = new SwordAttack(attacker, target);
            break;
        case MoveType::Spell:
            battleMove = new SpellAttack(attacker, target);
            break;
        case MoveType::Melee:
            battleMove = new MeleeAttack(attacker, target);
            break;
    }
    return battleMove;
}
