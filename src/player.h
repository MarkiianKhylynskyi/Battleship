#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"
#include <vector>
#include <string>

typedef std::pair<int16_t, int16_t> position;

class player
{
public:
	//Arranges ships on the primary grid
	virtual void past_ships() = 0;

	//
	virtual void shoot(player& plr, bool& flag) = 0;

	//Returns whether the player has ships which aren't drowned
	bool not_drowned_ships() const;

	const std::array<std::array<grid::Status, grid::GridSize>, grid::GridSize>& get_grid() const;

	const std::vector<position>& get_empty_cells() const;

	const std::string get_name() const;

	void set_grid(int16_t x, int16_t y, grid::Status status);

	void set_name(std::string name);

	void show(bool hidden);

protected:
	grid gr;
	std::vector<position> empty_cells;
	std::string name;

	void empty_cells_reset();
};

#endif //PLAYER_H