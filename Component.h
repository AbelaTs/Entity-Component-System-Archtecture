#ifndef CES_COMPONENT_H
#define CES_COMPONENT_H



typedef enum
{
	COMPONENT_NONE = 0,
	COMPONENT_DISPLACEMENT = 1 << 0,
	COMPONENT_VELOCITY = 1 << 1,
	COMPONENT_APPEARANCE = 1 << 2
} Component;



typedef struct
{
	float x;
	float y;
} Displacement;



typedef struct
{
	float x;
	float y;
} Velocity;



typedef struct
{
	char *name;
} Appearance;



#endif