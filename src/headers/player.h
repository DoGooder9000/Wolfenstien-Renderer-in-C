#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
	float angle;	// Angles are always going to be in radians, because of the math funciton in math.h
} PlayerCharacter;

void PlayerInit(PlayerCharacter* player);

#endif