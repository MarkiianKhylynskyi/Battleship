#include "grid.h"
#include <iostream>
#include <stdlib.h>
#include <set>
#include <Windows.h>

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

void grid::show(bool hidden)
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
				if (hidden)
				{
					std::cout << ' ';
				}
				else
				{
					std::cout << '#';
				}
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

void grid::f(int16_t i, int16_t j, int16_t& size)
{
	if ((i < 10) && (j < 10) && (gr[i][j] == Status::Ship))
	{
		gr[i][j] = Status::Empty;
		++size;
		f(i, j + 1, size);
		f(i + 1, j, size);
	}
	else return;
}

int16_t grid::find()
{
	int16_t size = 0;

	for (int16_t i = 0; i < GridSize; ++i)
	{
		for (int16_t j = 0; j < GridSize; ++j)
		{
			if (gr[i][j] == Status::Ship)
			{
				f(i, j, size);
				return size;
			}
		}
	}
	return size;
}

bool grid::correct_square(int16_t x, int16_t y)
{
	if ((gr[x][y] == Status::Ship) && (gr[x + 1][y + 1] == Status::Ship)) return false;
	if ((gr[x + 1][y] == Status::Ship) && (gr[x][y + 1] == Status::Ship)) return false;
	return true;
}

bool grid::correct_past() const
{
	grid Grid = *this;

	for (int16_t x = 0; x < 9; ++x)
	{
		for (int16_t y = 0; y < 9; ++y)
		{
			if (!Grid.correct_square(x, y)) return false;
		}
	}

	std::multiset<int16_t> sizes;
	std::multiset<int16_t> mset = { 1,1,1,1,2,2,2,3,3,4 };

	int16_t size = 0;
	for (int16_t i = 0; i < 10; ++i)
	{
		size = Grid.find();
		if (size != 0)
		{
			sizes.insert(size);
		}
	}

	std::multiset<int16_t>::iterator it = sizes.begin();
	while (it != sizes.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	if (sizes != mset) return false;

	return true;
}
