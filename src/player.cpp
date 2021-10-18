#include "player.h"

#include <iostream>

bool player::not_drowned_ships() const
{
	for (int16_t i = 0; i < grid::GridSize; ++i)
	{
		for (int16_t j = 0; j < grid::GridSize; ++j)
		{
			if (gr.get()[i][j] == grid::Status::Ship) return true;
		}
	}
	return false;
}

const std::array<std::array<grid::Status, grid::GridSize>, grid::GridSize>& player::get_grid() const
{
	return gr.get();
}

const std::vector<position>& player::get_empty_cells() const
{
	return empty_cells;
}

const std::string player::get_name() const
{
	return name;
}

void player::set_grid(int16_t x, int16_t y, grid::Status status)
{
	gr.set(x, y, status);
}

void player::set_name(std::string name)
{
	this->name = name;
}

void player::show(bool hidden)
{
	std::cout << name << "\'s grid\n\n";
	gr.show(hidden);
}

void player::empty_cells_reset()
{
	empty_cells.clear();
	for (int16_t i = 0; i < grid::GridSize; ++i)
	{
		for (int16_t j = 0; j < grid::GridSize; ++j)
		{
			empty_cells.push_back(position(i, j));
		}
	}
}