#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

#include <iterator>
#include <utility>
#include <random>

class computer : public player
{
public:
	computer();

	//Arranges ships on the primary grid
	void past_ships() override;

	void shoot(player& plr, bool& flag) override;

private:
	static std::mt19937 mt;
	std::vector<position> wounded_ship;

	//Return a random number from the interval [0,max]
	int16_t random(int16_t max) const;

	//Erases the elment pos from the vector vec
	void erase_from_vector(std::vector<position>& vec, position pos);

	//Erases the elment pos from the vector vec
	void erase_from_vector(std::vector<position>& vec, position pos) const;

	std::vector<position> posible_past_positions(bool vertical, int16_t size) const;

	std::vector<position> posible_positions() const;

	//Returns a shoot position when there is a wounded ship
	position shoot_with_wounded_ship() const;

	//Returns a shoot position when there isn't a wounded ship
	position shoot_without_wounded_ship() const;

	//Arranges a ship with length size on the primary grid
	bool past_ship(int16_t size);
};

#endif //COMPUTER_H