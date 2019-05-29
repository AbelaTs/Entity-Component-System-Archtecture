#include "Component.h"
#include "Entity.h"

#include <stdio.h>



unsigned int createEntity(World *world)
{
	unsigned int entity;
	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if(world->mask[entity] == COMPONENT_NONE)
		{
			printf("Entity created: %d\n", entity);
			return(entity);
		}
	}

	printf("Error!  No more entities left!\n");
	return(ENTITY_COUNT);
}



void destroyEntity(World *world, unsigned int entity)
{
	printf("Entity destroyed: %d\n", entity);
	world->mask[entity] = COMPONENT_NONE;
}



unsigned int createTree(World *world, float x, float y)
{
	unsigned int entity = createEntity(world);

	world->mask[entity] = COMPONENT_DISPLACEMENT | COMPONENT_APPEARANCE;

	world->displacement[entity].x = x;
	world->displacement[entity].y = y;

	world->appearance[entity].name = "Tree";

	return(entity);
}



unsigned int createBox(World *world, float x, float y, float vx, float vy)
{
	unsigned int entity = createEntity(world);

	world->mask[entity] = COMPONENT_DISPLACEMENT | COMPONENT_VELOCITY | COMPONENT_APPEARANCE;

	world->displacement[entity].x = x;
	world->displacement[entity].y = y;

	world->velocity[entity].x = vx;
	world->velocity[entity].y = vy;

	world->appearance[entity].name = "Box";

	return(entity);
}



unsigned int createGhost(World *world, float x, float y, float vx, float vy)
{
	unsigned int entity = createEntity(world);

	world->mask[entity] = COMPONENT_DISPLACEMENT | COMPONENT_VELOCITY;

	world->displacement[entity].x = x;
	world->displacement[entity].y = y;

	world->velocity[entity].x = vx;
	world->velocity[entity].y = vy;

	return(entity);
}