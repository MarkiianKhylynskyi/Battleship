#ifndef COMPUTER_H
#define COMPUTER_H

#include"player.h"

#include<iterator>
#include<utility>
#include<algorithm>
#include<random>
#include<Windows.h>

class computer : public player
{
private:
	static std::mt19937 mt;
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

	//Returns a shoot position when there is a wounded ship
	position shoot_with_wounded_ship() const;

	//Returns a shoot position when there isn't a wounded ship
	position shoot_without_wounded_ship() const;

	//Arranges a ship with length size on the primary grid
	bool past_ship(int16_t size);
public:
	computer();

	//Arranges ships on the primary grid
	void past_ships() override;

	void shoot(player& plr, bool& flag) override;
};

#endif //COMPUTER_H