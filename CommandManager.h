//
//  CommandManager.hpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/29/20.
//

#pragma once
#ifndef CommandManager_h
#define CommandManager_h

#include "BattleMove.h"
#include "Stack.hpp"

class CommandManager {
private:
    Stack<BattleMove*> stack;

public:
    CommandManager();
    void Execute(BattleMove* command);
    void Undo();
    ~CommandManager();
};

#endif /* CommandManager_h */
