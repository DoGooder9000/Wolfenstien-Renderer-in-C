#include "headers/player.h"
#include "headers/settings.h"

void PlayerInit(PlayerCharacter* player){
	player->angle = 0;
	player->screen_x = WINDOW_WIDTH/2;
	player->screen_y = WINDOW_HEIGHT/2;
}