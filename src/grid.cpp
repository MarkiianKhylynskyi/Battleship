#include"grid.h"

grid::grid()
{
	for (size_t i = 0; i < MapSize; ++i)
	{
		for (size_t j = 0; j < MapSize; ++j)
		{
			gr[i][j] = Status::Empty;
		}
	}
}

const std::array<std::array<grid::Status, grid::MapSize>, grid::MapSize>& grid::get() const
{
	return gr;
}

void grid::set(int16_t x, int16_t y, Status status)
{
	gr[x][y] = status;
}