#ifndef CES_ENTITY_H
#define CES_ENTITY_H



#define ENTITY_COUNT 100

typedef struct
{
	int mask[ENTITY_COUNT];

	Displacement displacement[ENTITY_COUNT];
	Velocity velocity[ENTITY_COUNT];
	Appearance appearance[ENTITY_COUNT];
} World;



unsigned int createEntity(World *world);

void destroyEntity(World *world, unsigned int entity);



unsigned int createTree(World *world, float x, float y);

unsigned int createBox(World *world, float x, float y, float vx, float vy);

unsigned int createGhost(World *world, float x, float y, float vx, float vy);



#endif