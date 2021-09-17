#ifndef COMPUTER_H
#define COMPUTER_H

#include"player.h"

#include<set>
#include<iterator>
#include<utility>
#include<algorithm>
#include<random>

typedef std::pair<int16_t, int16_t> pair;

//std::vector<pair>  vector_intersection(std::vector<pair>& v1, std::vector<pair>& v2);

class computer : public player
{
private:
	//std::random_device rd;
	//std::mt19937 mt;
	std::set<pair> empty_cells;
	std::set<pair> wounded_ship;

	std::set<pair> posible_positions() const;

	//
	pair shoot_with_wounded_ship() const;

	//
	pair shoot_without_wounded_ship() const;

	void past_ship(size_t size);
public:
	computer();

	void past_ships() override;

	void shoot(player& plr, bool flag) override;
};

#endif