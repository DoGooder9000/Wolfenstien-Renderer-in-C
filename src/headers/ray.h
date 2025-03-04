#ifndef RAY_H
#define RAY_H

#include "player.h"
#include "settings.h"
#include "geofunctions.h"

typedef struct{
	float angle; // Direction in Radians

	float start_x;
	float start_y;

	float current_x;
	float current_y;
} Ray;

Ray InitRay(float angle, float start_x, float start_y);
void StepRay(Ray* ray);
Ray CastRayFromPlayerCharacter(PlayerCharacter* Player, float angle);
void CastRaysFromPlayer(PlayerCharacter* Player, Ray* ray_list);

#endif