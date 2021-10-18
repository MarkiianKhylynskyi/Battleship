#ifndef GAME_H
#define GAME_H

#include "player.h"

class game
{
private:
	player& first_player;
	player& second_player;
	bool game_continues = true;
	bool shoots_firs_player = true;
public:
	game(player& first_player, player& second_player);

	void set_first_name();
	void set_second_name();
	void set_names();
	void play();
};

#endif //GAME_H