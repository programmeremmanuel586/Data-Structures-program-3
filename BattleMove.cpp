//
//  BattleMove.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/16/20.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Actor.h"
#include "BattleMove.h"


// BattleMove object (Stores attack and heal functions)

// self: attacker | other: target (Note to self)
BattleMove::BattleMove(Actor* self, Actor* other)
  : self{self},
  other{other}
{}

void CurseAttack::Execute() {
    // Seed random number
    // Only needs to be generated once per class since we want to store the same number for healing move :)
    int damageDone = rand() % 15 + 5;
    this->damageTracker = damageDone;
    this->other->Hit(damageDone);
    std::cout << *this->other << " is cursed with " << damageDone << " damage.\n";
}
void CurseAttack::Undo() {
    int healingDone = damageTracker;
    other->Heal(healingDone);
}


void SwordAttack::Execute() {
    int damageDone = rand() % 21;
    damageTracker = damageDone;
    other->Hit(damageDone);
    std::cout << *this->other << " gets sliced with " << damageDone << " damage.\n";
}
void SwordAttack::Undo() {
    int healingDone = damageTracker;
    other->Heal(healingDone);
}

void SpellAttack::Execute() {
    int damageDone = rand() % 21;
    damageTracker = damageDone;
    other->Hit(damageDone);
    std::cout << *this->other << " is magically attacked with " << damageDone << " damage. ";
}
void SpellAttack::Undo() {
    int healingDone = damageTracker;
    other->Heal(healingDone);
}


void MeleeAttack::Execute() {
    int damageDone = rand() % 15 + 5;
    this->damageTracker = damageDone;
    this->other->Hit(damageDone);
    std::cout << *this->other << " is brutally beaten with " << damageDone << " damage. ";
}
void MeleeAttack::Undo() {
    int healingDone = this->damageTracker;
    this->other->Heal(healingDone);
}
