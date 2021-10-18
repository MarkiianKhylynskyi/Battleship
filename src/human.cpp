#include "human.h"
#include <iostream>

human::human()
{
	empty_cells_reset();
}

void human::set_name(std::string name)
{
	this->name = name;
}

void human::past_ships()
{
	char y = 0;
	int16_t x = 0;

	do
	{
		gr.reset();
		for (int16_t i = 0; i < 20; ++i)
		{
			do
			{
				system("cls");
				std::cout << "Past ships\n";
				show(0);
				std::cout << std::endl << "Position: ";
				std::cin >> y >> x;
			} while ((x < 0) || (x > 9) || (y < 65) || (y > 74));
			gr.set(x, y - 65, grid::Status::Ship);
		}
	} while (!gr.correct_past());
	
}

void human::shoot(player& plr, bool& flag)
{
	std::cout << std::endl;
	char y = 0;
	int16_t x = 0;
	position shoot_position;
	do
	{
		std::cout << name << ": ";
		std::cin >> y >> x;
		system("cls");
		shoot_position.first = x;
		shoot_position.second = y - 65;
	} while (std::find(empty_cells.begin(), empty_cells.end(), shoot_position) == empty_cells.end());

	empty_cells.erase(std::find(empty_cells.begin(), empty_cells.end(), shoot_position));

	if (plr.get_grid()[shoot_position.first][shoot_position.second] == grid::Status::Ship)
	{
		plr.set_grid(shoot_position.first, shoot_position.second, grid::Status::WoundedShip);
	}
	else
	{
		plr.set_grid(shoot_position.first, shoot_position.second, grid::Status::Bomb);
		flag = !flag;
	}
}