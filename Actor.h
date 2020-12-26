//
//  Actor.hpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/26/20.
//

#pragma once
#ifndef Actor_hpp
#define Actor_hpp

#include <iostream>
#include <string>
#include <vector>
#include "enum.hpp"

// Base class
class Actor {
protected:
    std::string type;   // is supposed to be the name of the actor (Knight/Ghost)
    int health;

public:
    Actor(int health, std::string type);

    // Abstract class needs virtual destructor
    virtual ~Actor() = default;

    void SetType(std::string s);
    const std::string& GetType() const;
    virtual void Hit(int damage) { health -= damage; }
    virtual void Heal(int amount) { health += amount; }
    virtual const std::vector<MoveType>& GetMoves() = 0;

    bool IsDead() const;
    friend std::ostream& operator<<(std::ostream& out, const Actor& actor);
};


// Derived classes (Possible characters)

// Ghost
class GhostActor: public Actor {
public:
    GhostActor();
    const std::vector<MoveType>& GetMoves() override;   // implements own version of GetMoves()
};

// Knight
class KnightActor: public Actor {
  public:
    KnightActor();
    const std::vector<MoveType>& GetMoves() override;   // implements own version of GetMoves()
};

#endif /* Actor_hpp */
