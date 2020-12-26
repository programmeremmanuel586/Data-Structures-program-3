//
//  ActorFactory.hpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/29/20.
//

#ifndef ActorFactory_h
#define ActorFactory_h

#include <iostream>
#include "Actor.h"
#include "enum.hpp"

class ActorFactory {
public:
    // This function creates a new character/actor
    static Actor* CreateActor(ActorType actorType);
};


#endif /* ActorFactory_h */
