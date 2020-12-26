//
//  CommandManager.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/16/20.
//

#include <iostream>
#include <stdlib.h>
#include "CommandManager.h"
#include "BattleMove.h"
#include "Stack.hpp"

CommandManager::CommandManager() :stack{Stack<BattleMove*>(100)} {}    // Make sure to implement a destructor for those pointer elements!

// Undoable Command is the Battle Move Interface (so BattleMove is the argument) Note to self
void CommandManager::Execute(BattleMove* command) {
    // Executes the BattleMove
    command->Execute();

    // Push the BattleMove to the stack
    stack.Push(command);
}
void CommandManager::Undo() {
    // Check if stack is empty
    if (stack.IsEmpty()) {
        std::cout << "There is nothing to undo\n";
        // exit(EXIT_SUCCESS);
    }
    // identify BattleMove on top of stack; this variable holds the BattleMove object
    BattleMove* command = stack.Top();

    // undo the action done by the BattleMove
    command->Undo();

    // clear the contents of the BattleMove instance
    // delete stack.Top();

    // remove the BattleMove from the stack
    stack.Pop();
}

CommandManager::~CommandManager() {
    while(!stack.IsEmpty()) {
        // delete stack.Top();
        stack.Pop();
    }
}
