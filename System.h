#ifndef CES_SYSTEM_H
#define CES_SYSTEM_H

#include "Component.h"
#include "Entity.h"



typedef void (* SystemFunction)(World *world, unsigned int entity);



void movementFunction(World *world);

void renderFunction(World *world);



#endif