#ifndef SETTINGS_H
#define SETTINGS_H

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

extern const char* WINDOW_TITLE;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;

extern const int TILE_WIDTH;
extern const int TILE_HEIGHT;

extern float PLAYER_MOVE_SPEED;
extern float PLAYER_TURN_SPEED;

extern int PLAYER_DRAW_RADIUS;

extern const int FPS_CAP;

extern float RAY_STEP_SIZE;

extern float FOV; // in radians
extern int RAYS_IN_FOV;

extern int map[MAP_HEIGHT][MAP_WIDTH];

#endif