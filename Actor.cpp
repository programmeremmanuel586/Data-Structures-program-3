//
//  Actor.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/26/20.
//

#include "Actor.h"
#include <iostream>
#include <string>
#include <vector>
#include "enum.hpp"

// For Actor

Actor::Actor(int health, std::string type):
    type{type},
    health{health}
{}

// Sets Actor type
void Actor::SetType(std::string s) {
    type = s;
}

// Gets Actor type
const std::string& Actor::GetType() const {
    return type;
}

bool Actor::IsDead() const { return health <= 0; }

std::ostream& operator<<(std::ostream& out, const Actor& actor) {
    return out << actor.type << ", " << "(" << actor.health << ")";
}

// ----------------------------------------------------------------------------------

namespace {
const std::vector<MoveType> ghost_moves = { MoveType::Spell, MoveType::Curse };
}

// For Ghost
GhostActor::GhostActor()
  : Actor{100, "Ghost"}
{}

const std::vector<MoveType>& GhostActor::GetMoves() {
  return ghost_moves;
}

// ----------------------------------------------------------------------------------


namespace {
const std::vector<MoveType> knight_moves = { MoveType::Sword, MoveType::Melee };
}

// For Knight
KnightActor::KnightActor()
  : Actor{100, "Knight"}
{}

const std::vector<MoveType>& KnightActor::GetMoves() {
    return knight_moves;
}
