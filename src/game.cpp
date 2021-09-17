#include"game.h"

game::game(player& first_player, player& second_player)
	: first_player(first_player), second_player(second_player)
{

}

void game::play()
{
	first_player.past_ships();
	second_player.past_ships();
	while (game_continues)
	{
		if (shoots_firs_player)
		{
			first_player.shoot();
			game_continues = second_player.not_drowned_ships();
		}
		else
		{
			second_player.shoot();
			game_continues = first_player.not_drowned_ships();
		}
	}
}