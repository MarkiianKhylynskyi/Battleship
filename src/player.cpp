#include"player.h"

bool player::not_drowned_ships() const
{
	for (size_t i = 0; i < grid::MapSize; ++i)
	{
		for (size_t j = 0; j < grid::MapSize; ++j)
		{
			if (gr.get()[i][j] == grid::Status::Ship) return true;
		}
	}
	return false;
}

const std::array<std::array<grid::Status, grid::MapSize>, grid::MapSize>& player::get_grid() const
{
	return gr.get();
}

void player::set_grid(int16_t x, int16_t y, grid::Status status)
{
	gr.set(x, y, status);
}