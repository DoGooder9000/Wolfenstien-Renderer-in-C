#include "headers/geofunctions.h"
#include "headers/settings.h"

#define _USE_MATH_DEFINES

#include <math.h>

double Distance(float point1_x, float point1_y, float point2_x, float point2_y){
	float x_dist = point2_x - point1_x;
	float y_dist = point2_y - point1_y; 

	return sqrt((double)(powf(x_dist, 2) + powf(y_dist, 2)));
}

float GetXFromAngle(float angle, float magnitude){
	return (float)cos(angle) * magnitude;
}

float GetYFromAngle(float angle, float magnitude){
	return (float)sin(angle) * magnitude;
}

void ScreenToMapCoords(int screen_x, int screen_y, int* map_x, int* map_y){
	*map_x = screen_x / TILE_WIDTH;
	*map_y = screen_y / TILE_HEIGHT;
}

float DegreesToRadians(float degrees){
	return degrees * (M_PI/180);
}

float RadiansToDegrees(float radians){
	return radians * (180/M_PI);
}

float Map(float x, float in_min, float in_max, float out_min, float out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}