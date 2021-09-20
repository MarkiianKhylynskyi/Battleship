#ifndef COMPUTER_H
#define COMPUTER_H

#include"player.h"

#include<vector>
#include<iterator>
#include<utility>
#include<algorithm>
#include<random>
#include<Windows.h>

typedef std::pair<int16_t, int16_t> position;

class computer : public player
{
private:
	static std::mt19937 mt;
	std::vector<position> empty_cells;
	std::vector<position> wounded_ship;

	//Return a random number from the interval [0,max]
	int16_t random(int16_t max) const;

	//Erases the elment pos from the vector vec
	void erase_from_vector(std::vector<position>& vec, position pos);

	//Erases the elment pos from the vector vec
	void erase_from_vector(std::vector<position>& vec, position pos) const;

	void empty_cells_reset();

	std::vector<position> posible_past_positions(bool vertical, int16_t siz) const;

	std::vector<position> posible_positions() const;

	//
	position shoot_with_wounded_ship() const;

	//
	position shoot_without_wounded_ship() const;

	bool past_ship(int16_t size);
public:
	computer();

	void past_ships() override;

	void shoot(player& plr, bool& flag) override;
};

#endif