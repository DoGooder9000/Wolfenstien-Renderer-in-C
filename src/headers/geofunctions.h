#ifndef GEO_FUNC_H
#define GEO_FUNC_H

double Distance(float point1_x, float point1_y, float point2_x, float point2_y);
float GetXFromAngle(float angle, float magnitude);
float GetYFromAngle(float angle, float magnitude);
void ScreenToMapCoords(int screen_x, int screen_y, int* map_x, int* map_y);
float DegreesToRadians(float degrees);
float RadiansToDegrees(float radians);
float Map(float x, float in_min, float in_max, float out_min, float out_max);

#endif