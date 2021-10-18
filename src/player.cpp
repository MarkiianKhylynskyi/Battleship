#include <algorithm>

#include "player.hpp"

bool player::not_drowned_ships() const
{
	for (auto &a: gr.get()) {
		auto it = std::find(a.begin(), a.end(), grid::Status::Ship);
		if (it != a.end())
			return true;
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

void player::set_grid(const position &pos, grid::Status status)
{
	gr.set(pos.first, pos.second, status);
}

void player::print()
{
	gr.print();
}
