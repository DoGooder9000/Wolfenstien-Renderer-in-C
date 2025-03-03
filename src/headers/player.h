#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
	float angle;	// Angles are always going to be in radians, because of the math funciton in math.h

	float screen_x;
	float screen_y;

} PlayerCharacter;

void PlayerInit(PlayerCharacter* player);
void MovePlayer(PlayerCharacter* player, float magnitude);
void TurnPlayer(PlayerCharacter* player, float angle);

#endif