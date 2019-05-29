#include "System.h"

#include <stdio.h>



#define MOVEMENT_MASK (COMPONENT_DISPLACEMENT | COMPONENT_VELOCITY)
#define RENDER_MASK (COMPONENT_DISPLACEMENT | COMPONENT_APPEARANCE)

void movementFunction(World *world)
{
	unsigned int entity;
	Displacement *d;
	Velocity *v;

	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if((world->mask[entity] & MOVEMENT_MASK) == MOVEMENT_MASK)
		{
			d = &(world->displacement[entity]);
			v = &(world->velocity[entity]);

			v->y -= 0.98f;

			d->x += v->x;
			d->y += v->y;
		}
	}
}





void renderFunction(World *world)
{
	unsigned int entity;
	Displacement *d;
	Appearance *a;

	for(entity = 0; entity < ENTITY_COUNT; ++entity)
	{
		if((world->mask[entity] & RENDER_MASK) == RENDER_MASK)
		{
			d = &(world->displacement[entity]);
			a = &(world->appearance[entity]);

			printf("%s at (%f, %f)\n", a->name, d->x, d->y);
		}
	}
}
