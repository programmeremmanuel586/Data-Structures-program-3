//
//  Game.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/29/20.
//

#include <iostream>
#include "Game.h"
#include "Battle.h"

Game::Game() {
    // Create an instance of the game
    Battle BattleGame;
    
    // Seed the game :D
    BattleGame.Game();
}
