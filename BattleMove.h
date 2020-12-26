//
//  BattleMove.hpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/29/20.
//

#pragma once
#ifndef BattleMove_h
#define BattleMove_h

#include "Actor.h"

// BattleMove object (Stores attack and heal functions)
class BattleMove {
protected:
    Actor* self{};
    Actor* other{};

public:
    virtual void Execute()=0;
    virtual void Undo()=0;
    // self: attacker | other: target (Note to self)
    BattleMove(Actor* self, Actor* other);
};

// The override keyword allows the implementation of the virtual function to overide the implementation in the base class.


// Curse Attack
class CurseAttack: public BattleMove {
private:
    // Keeps track of damage for curse attack
    int damageTracker;

public:
    using BattleMove::BattleMove;
    void Execute() override;
    void Undo() override;
};


// Sword Attack
class SwordAttack: public BattleMove {
private:
    // Keeps track of damage for sword attack
    int damageTracker;

public:
    using BattleMove::BattleMove;
    void Execute() override;
    void Undo() override;
};


// Spell Attack
class SpellAttack: public BattleMove {
private:
    // Keeps track of damage for spell attack
    int damageTracker;

public:
    using BattleMove::BattleMove;
    void Execute() override;
    void Undo() override;
};


// Melee Attack
class MeleeAttack: public BattleMove {
private:
    // Keeps track of damage for melee attack
    int damageTracker;

public:
    using BattleMove::BattleMove;
    void Execute() override;
    void Undo() override;
};


#endif /* BattleMove_h */
