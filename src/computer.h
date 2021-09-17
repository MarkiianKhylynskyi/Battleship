#ifndef COMPUTER_H
#define COMPUTER_H

#include"player.h"
#include"pair.h"

#include<vector>
#include<random>

std::vector<pair>  vector_intersection(std::vector<pair> v1, std::vector<pair> v2);

class computer : public player
{
private:
	//std::random_device rd;
	//std::mt19937 mt;
	std::vector<pair> empty_cells;
	std::vector<pair> wounded_ship;

	//
	pair shoot_with_wounded_ship() const;

	//
	pair shoot_without_wounded_ship() const;

	std::vector<pair> posible_positions() const;

	void past_ship(size_t size);
public:
	computer();

	void past_ships() override;

	void shoot() override;
};

#endif