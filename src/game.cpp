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
		//--------------------------------------
		system("cls");
		first_player.print();
		std::cout << std::endl;
		second_player.print();
		//--------------------------------------

		if (shoots_firs_player)
		{
			first_player.shoot(second_player, shoots_firs_player);
			game_continues = second_player.not_drowned_ships();
		}
		else
		{
			second_player.shoot(first_player, shoots_firs_player);
			game_continues = first_player.not_drowned_ships();
		}
	}
	system("cls");
	first_player.print();
	std::cout << std::endl;
	second_player.print();
	Sleep(1700);
	//system("cls");
	if (shoots_firs_player) std::cout << "Win first player" << std::endl;
	else std::cout << "Win second player" << std::endl;

}