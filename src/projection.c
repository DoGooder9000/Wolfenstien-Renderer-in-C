#include "headers/projection.h"

#include <math.h>

int CalculateWallHeight(Ray* ray, float player_angle){
	float distance = Distance(ray->start_x, ray->start_y, ray->current_x, ray->current_y);

	// Step 2: Correct fisheye effect
	float corrected_distance = distance * (float)cos(player_angle - ray->angle);
	float proj_plane_dist = (WINDOW_WIDTH / 2.0f) / tan(FOV / 2.0f);

	// Step 3: Calculate wall height (projection)
	int lineHeight = (int)(TILE_HEIGHT*proj_plane_dist / (corrected_distance + 0.0001f));
	//int lineHeight = (int)(21000 / (corrected_distance + 0.0001f)); // Avoid division by zero

	if (lineHeight > WINDOW_HEIGHT){ lineHeight = WINDOW_HEIGHT;}

	return lineHeight;
}