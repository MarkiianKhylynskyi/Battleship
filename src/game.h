#ifndef GAME_H
#define GAME_H

#include"player.h"

#include <stdlib.h>
#include<Windows.h>

class game
{
private:
	player& first_player;
	player& second_player;
	bool game_continues = true;
	bool shoots_firs_player = true;
public:
	game(player& first_player, player& second_player);

	void play();
};

#endif //GAME_H