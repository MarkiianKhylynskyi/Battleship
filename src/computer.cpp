#include"computer.h"

//-------------------- private methods --------------------

std::set<pair> computer::posible_positions() const
{
	std::set<pair> ret_positions;
	if (wounded_ship.empty())
	{
	}
	else if (wounded_ship.size() == 1)
	{
		std::set<pair> positions;
		int16_t x = (*wounded_ship.begin()).first;
		int16_t y = (*wounded_ship.begin()).second;
		positions.insert({ x + 1,y });
		positions.insert({ x,y + 1 });
		positions.insert({ x - 1,y });
		positions.insert({ x,y - 1 });
		std::set_intersection(positions.begin(), positions.end(), empty_cells.begin(), empty_cells.end(), 
			std::inserter(ret_positions,ret_positions.begin()));

	}
	else
	{
		std::set<pair> positions;
		std::set<pair>::iterator begin = wounded_ship.begin();
		std::set<pair>::iterator end = wounded_ship.end();
		--end;
		int16_t dif_x = ((*end).first - (*begin).first) / (wounded_ship.size() - 1);
		int16_t dif_y = ((*end).second - (*begin).second) / (wounded_ship.size() - 1);
		positions.insert({ (*begin).first - dif_x,(*begin).second - dif_y });
		positions.insert({ (*end).first + dif_x,(*end).second + dif_y });
		std::set_intersection(positions.begin(), positions.end(), empty_cells.begin(), empty_cells.end(),
			std::inserter(ret_positions, ret_positions.begin()));
	}
	return ret_positions;
}

pair computer::shoot_with_wounded_ship() const
{

	return { 1,1 };
}

pair computer::shoot_without_wounded_ship() const
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> uid(0, empty_cells.size() - 1);
	size_t index = uid(mt);
	std::set<pair>::iterator it = empty_cells.begin();
	std::advance(it, index);
	return *it;
}

void computer::past_ship(size_t size)
{

}

//-------------------- public methods --------------------

computer::computer()
{
	for (int16_t i = 0; i < grid::MapSize; ++i)
	{
		for (int16_t j = 0; j < grid::MapSize; ++j)
		{
			empty_cells.insert({ i,j });
		}
	}

	//mt = std::mt19937(rd());
}

void computer::past_ships()
{
	
}

void computer::shoot(player& plr, bool flag)
{
	pair position;
	if (wounded_ship.empty())
	{
		position = shoot_without_wounded_ship();
	}
	else
	{
		position = shoot_with_wounded_ship();
	}
}