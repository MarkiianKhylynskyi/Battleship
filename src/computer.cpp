#include"computer.h"

//-------------------- private methods --------------------

pair computer::shoot_with_wounded_ship() const
{
	return { 1,1 };
}

pair computer::shoot_without_wounded_ship() const
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> uid(0, empty_cells.size() - 1);
	pair position(uid(mt),uid(mt));
	return position;
}

std::vector<pair> computer::posible_positions() const
{
	std::vector<pair> positions;
	if (wounded_ship.size() == 0)
	{}
	else if (wounded_ship.size() == 1)
	{
		int16_t x = wounded_ship[0].x;
		int16_t y = wounded_ship[0].y;
		positions.push_back({ x + 1,y });
		positions.push_back({ x,y + 1 });
		positions.push_back({ x - 1,y });
		positions.push_back({ x,y - 1 });
	}
	else
	{

	}
	return positions;
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
			empty_cells.push_back({ i,j });
		}
	}

	//mt = std::mt19937(rd());
}

void computer::past_ships()
{
	
}

void computer::shoot()
{
	pair position;
	if (wounded_ship.size() == 0)
	{
		position = shoot_without_wounded_ship();
	}
	else
	{
		position = shoot_with_wounded_ship();
	}
}

std::vector<pair> vector_intersection(std::vector<pair> v1, std::vector<pair> v2)
{
	return std::vector<pair>();
}
