#include "headers/player.h"
#include "headers/settings.h"
#include "headers/geofunctions.h"

#include <math.h>

void PlayerInit(PlayerCharacter* player){
	player->angle = 0;
	player->screen_x = WINDOW_WIDTH/2;
	player->screen_y = WINDOW_HEIGHT/2;


}

void MovePlayer(PlayerCharacter* player, float magnitude){
	player->screen_x += GetXFromAngle(player->angle, magnitude);
	player->screen_y += GetYFromAngle(player->angle, magnitude);
}

void TurnPlayer(PlayerCharacter* player, float angle){
	player->angle += angle;
}