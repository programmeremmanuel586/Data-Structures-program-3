//
//  functions.h
//  program_3
//
//  Created by Emmanuel Amoh on 11/29/20.
//

#pragma once
#ifndef functions_h
#define functions_h

#include <string>
#include "BattleMove.h"

int RandNumGenerator(int min, int max);
std::string actorDisplayName(ActorType actortype);
std::string moveDisplayName(MoveType movetype);
void invalidInputChecker(int num);
void invalidMenuInputChecker(int num);

#endif /* functions_h */
