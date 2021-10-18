#ifndef PLAYER_H
#define PLAYER_H

#include"grid.hpp"

#include<vector>

typedef std::pair<int16_t, int16_t> position;

class player
{
protected:
	grid gr;
	std::vector<position> empty_cells;
public:
	//Arranges ships on the primary grid
	virtual void past_ships() = 0;

	//
	virtual void shoot(player& plr, bool& flag) = 0;

	//Returns whether the player has ships which aren't drowned
	bool not_drowned_ships() const;

	const std::array<std::array<grid::Status, grid::GridSize>, grid::GridSize>& get_grid() const;

	const std::vector<position>& get_empty_cells() const;

	void set_grid(const position &pos, grid::Status status);

	void print();
};

#endif //PLAYER_H
