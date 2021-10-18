#include <iostream>

#include "grid.hpp"

void grid::reset()
{
	for (auto &a: gr)
		a.fill(Status::Empty);
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

static std::ostream &operator<<(std::ostream &o, grid::Status s)
{
	switch (s) {
	case grid::Status::Empty: return o << ' ';
	case grid::Status::Bomb: return o << '*';
	case grid::Status::Ship: return o << '#';
	case grid::Status::WoundedShip: return o << 'x';
	default: return o;
	}
}

void grid::print()
{
	std::cout << "  ABCDEFGHIJ" << std::endl << std::endl;

	int i = 0;
	for (auto &a: gr) {
		std::cout << i << ' ';
		for (auto &b: a)
			std::cout << b;
		std::cout << std::endl;
		++i;
	}
}
