#ifndef PLAYER_H
#define PLAYER_H

#include"grid.h"

class player
{
protected:
	grid gr;
public:
	//Arranges ships on the primary grid
	virtual void past_ships() = 0;

	//
	virtual void shoot(player& plr, bool& flag) = 0;

	//Returns whether the player has ships which aren't drowned
	bool not_drowned_ships() const;

	const std::array<std::array<grid::Status, grid::GridSize>, grid::GridSize>& get_grid() const;

	void set_grid(int16_t x, int16_t y, grid::Status status);

	void print();
};

#endif