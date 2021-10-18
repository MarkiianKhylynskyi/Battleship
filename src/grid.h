#ifndef GRID_H
#define GRID_H

#include <array>
#include <cstdint>

class grid
{
public:
	enum class Status
	{
		Empty,
		Bomb,
		Ship,
		WoundedShip
	};
	static const int16_t GridSize = 10;

	grid();

	const std::array<std::array<Status, GridSize>, GridSize>& get() const;

	//Fills the grid by Status::Empty
	void reset();
	void set(int16_t x, int16_t y, Status status);
	void show(bool hidden);
	
	bool correct_past() const;

private:

	std::array<std::array<Status, GridSize>, GridSize> gr;

	void f(int16_t x, int16_t y, int16_t& size);
	int16_t find();
	bool correct_square(int16_t x, int16_t y);
};

#endif //GRID_H