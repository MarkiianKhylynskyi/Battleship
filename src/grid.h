#ifndef GRID_H
#define GRID_H

#include<array>
#include<cstdint>
#include<iostream>

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
private:
	
	std::array<std::array<Status,GridSize>,GridSize> gr;
public:
	grid();

	const std::array<std::array<Status, GridSize>, GridSize>& get() const;

	//Fills the grid by Status::Empty
	void reset();

	void set(int16_t x, int16_t y, Status status);

	void print();
};

#endif //GRID_H