#include "headers/ray.h"

Ray InitRay(float angle, float start_x, float start_y){
	Ray ray = {angle, start_x, start_y, start_x, start_y};

	return ray;
}

void StepRay(Ray* ray){
	ray->current_x += GetXFromAngle(ray->angle, RAY_STEP_SIZE);
	ray->current_y += GetYFromAngle(ray->angle, RAY_STEP_SIZE);
}

Ray CastRayFromPlayerCharacter(PlayerCharacter* Player, float angle){
	Ray ray = InitRay(angle, Player->screen_x, Player->screen_y);

	int map_x;
	int map_y;

	ScreenToMapCoords(ray.current_x, ray.current_y, &map_x, &map_y);

	while (map[map_y][map_x] == 0){
		StepRay(&ray);
		ScreenToMapCoords(ray.current_x, ray.current_y, &map_x, &map_y);
	}

	return ray;
}

void CastRaysFromPlayer(PlayerCharacter* Player, Ray* ray_list){
	float ANGLE_PER_RAY = FOV/RAYS_IN_FOV;

	float angle;

	for (int i=0; i<RAYS_IN_FOV; i++){
		angle = Player->angle - (FOV/2) + (i * ANGLE_PER_RAY);

		ray_list[i] = CastRayFromPlayerCharacter(Player, angle);
	}
}