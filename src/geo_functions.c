#include "headers/geofunctions.h"
#include <math.h>

double Distance(float point1_x, float point1_y, float point2_x, float point2_y){
	float x_dist = point2_x - point1_x;
	float y_dist = point2_y - point1_y; 

	return sqrt((double)(powf(x_dist, 2) + powf(y_dist, 2)));
}