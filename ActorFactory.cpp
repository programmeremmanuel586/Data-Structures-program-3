//
//  ActorFactory.cpp
//  program_3
//
//  Created by Emmanuel Amoh on 11/16/20.
//

#include <iostream>
#include "Actor.h"
#include "ActorFactory.h"
#include "enum.hpp"

Actor* ActorFactory::CreateActor(ActorType actorType) {
    Actor* actor = nullptr;
    switch (actorType) {
        case ActorType::Ghost:
            actor = new GhostActor();
            break;
        case ActorType::Knight:
            actor = new KnightActor();
            break;
    }
    return actor;
}
