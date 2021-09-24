#include"human.h"

human::human(std::function<grid()> func_past_ships, std::function<position()> func_shoot)
	: func_past_ships(func_past_ships), func_shoot(func_shoot)
{}

void human::past_ships()
{
	gr = func_past_ships();
}

void human::shoot(player& plr, bool& flag)
{
	position shoot_position = func_shoot();

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