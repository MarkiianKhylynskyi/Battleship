#include "game.h"
#include <iostream>
#include <Windows.h>

game::game(player& first_player, player& second_player)
	: first_player(first_player), second_player(second_player)
{

}

void game::set_first_name()
{
	std::string name;

	system("cls");
	std::cout << "Player's name: ";
	std::cin >> name;
	first_player.set_name(name);
}

void game::set_second_name()
{
	std::string name;

	system("cls");
	std::cout << "Player's name: ";
	std::cin >> name;
	second_player.set_name(name);
}

void game::set_names()
{
	std::string name;

	system("cls");
	std::cout << "First player's name: ";
	std::cin >> name;
	first_player.set_name(name);

	std::cout << std::endl;

	std::cout << "Second player's name: ";
	std::cin >> name;
	second_player.set_name(name);
}

void game::play()
{
	first_player.past_ships();
	second_player.past_ships();
	while (game_continues)
	{
		//--------------------------------------
		system("cls");
		first_player.show(1);
		std::cout << std::endl;
		second_player.show(1);
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
	first_player.show(1);
	std::cout << std::endl;
	second_player.show(1);
	Sleep(500);

	if (shoots_firs_player) std::cout << "Win " << first_player.get_name() << std::endl;
	else std::cout << "Win " << second_player.get_name() << std::endl;
	Sleep(3000);
}