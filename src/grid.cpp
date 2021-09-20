#include"grid.h"

void grid::reset()
{
	for (int16_t i = 0; i < GridSize; ++i)
	{
		for (int16_t j = 0; j < GridSize; ++j)
		{
			gr[i][j] = Status::Empty;
		}
	}
}

grid::grid()
{
	reset();
}

const std::array<std::array<grid::Status, grid::GridSize>, grid::GridSize>& grid::get() const
{
	return gr;
}

void grid::set(int16_t x, int16_t y, Status status)
{
	gr[x][y] = status;
}

void grid::print()
{
	for (char ch : {' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'})
	{
		std::cout << ch;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int16_t i = 0; i < GridSize; ++i)
	{
		std::cout << i << ' ';
		for (int16_t j = 0; j < GridSize; ++j)
		{
			switch (gr[i][j])
			{
			case Status::Empty:
			{
				std::cout << ' ';
				break;
			}
			case Status::Bomb:
			{
				std::cout << '*';
				break;
			}
			case Status::Ship:
			{
				std::cout << '#';
				break;
			}
			case Status::WoundedShip:
			{
				std::cout << 'x';
				break;
			}
			}
		}
		std::cout << std::endl;
	}
}