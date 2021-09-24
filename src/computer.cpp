#include"computer.h"

std::mt19937 computer::mt;

//-------------------- private methods --------------------

int16_t computer::random(int16_t max) const
{
	std::uniform_int_distribution<int> uid(0, max);
	return uid(mt);
}

void computer::erase_from_vector(std::vector<position>& vec, position pos)
{
	std::vector<position>::iterator it = std::find(vec.begin(), vec.end(), pos);
	if (it != vec.end())
	{
		vec.erase(it);
	}
}

void computer::erase_from_vector(std::vector<position>& vec, position pos) const
{
	std::vector<position>::iterator it = std::find(vec.begin(), vec.end(), pos);
	if (it != vec.end())
	{
		vec.erase(it);
	}
}

void computer::empty_cells_reset()
{
	empty_cells.clear();
	for (int16_t i = 0; i < grid::GridSize; ++i)
	{
		for (int16_t j = 0; j < grid::GridSize; ++j)
		{
			empty_cells.push_back(position(i,j));
		}
	}
}

std::vector<position> computer::posible_past_positions(bool vertical, int16_t size) const
{
	std::vector<position> positions = empty_cells;
	if (vertical)
	{
		for (position pos : empty_cells)
		{
			if (std::find(empty_cells.begin(), empty_cells.end(), position(pos.first + 1, pos.second)) == empty_cells.end())
			{
				for (int16_t x = 0; x < size - 1; ++x)
				{
					erase_from_vector(positions, position(pos.first - x, pos.second));
				}
			}
		}
	}
	else
	{
		for (position pos : empty_cells)
		{
			if (std::find(empty_cells.begin(), empty_cells.end(), position(pos.first, pos.second + 1)) == empty_cells.end())
			{
				for (int16_t y = 0; y < size - 1; ++y)
				{
					erase_from_vector(positions, position(pos.first, pos.second - y));
				}
			}
		}
	}
	return positions;
}

bool computer::past_ship(int16_t size)
{
	bool vertical = random(1);

	std::vector<position> positions = posible_past_positions(vertical, size);
	if (positions.size() > 0) {
		position pos = positions[random(positions.size() - 1)];

		if (vertical)
		{
			for (int16_t x = 0; x < size; ++x)
			{
				gr.set(pos.first + x, pos.second, grid::Status::Ship);
			}

			for (int16_t x = pos.first - 1; x < pos.first + size + 1; ++x)
			{
				for (int16_t y = pos.second - 1; y < pos.second + 2; ++y)
				{
					erase_from_vector(empty_cells, position(x, y));
				}
			}
		}
		else
		{
			for (int16_t y = 0; y < size; ++y)
			{
				gr.set(pos.first, pos.second + y, grid::Status::Ship);
			}

			for (int16_t y = pos.second - 1; y < pos.second + size + 1; ++y)
			{
				for (int16_t x = pos.first - 1; x < pos.first + 2; ++x)
				{
					erase_from_vector(empty_cells, position(x, y));
				}
			}
		}
		return false;
	}
	else return true;
}

std::vector<position> computer::posible_positions() const
{
	std::vector<position> ret_positions;
	if (wounded_ship.empty())
	{
	}
	else if (wounded_ship.size() == 1)
	{
		std::vector<position> positions;
		int16_t x = wounded_ship[0].first;
		int16_t y = wounded_ship[0].second;
		positions.push_back({ x + 1,y });
		positions.push_back({ x,y + 1 });
		positions.push_back({ x - 1,y });
		positions.push_back({ x,y - 1 });
		std::sort(positions.begin(), positions.end());

		std::set_intersection(positions.begin(), positions.end(), empty_cells.begin(), empty_cells.end(), 
			std::back_inserter(ret_positions));
	}
	else
	{
		std::vector<position> positions;
		const int16_t size = wounded_ship.size() - 1;
		
		int16_t dif_x = (wounded_ship[size].first - wounded_ship[0].first) / (size);
		int16_t dif_y = (wounded_ship[size].second - wounded_ship[0].second) / (size);
		positions.push_back({ wounded_ship[0].first - dif_x,wounded_ship[0].second - dif_y });
		positions.push_back({ wounded_ship[size].first + dif_x,wounded_ship[size].second + dif_y });
		std::sort(positions.begin(), positions.end());

		std::set_intersection(positions.begin(), positions.end(), empty_cells.begin(), empty_cells.end(),
			std::back_inserter(ret_positions));
	}
	return ret_positions;
}

position computer::shoot_with_wounded_ship() const
{
	std::vector<position> positions = posible_positions();
	int16_t index = random(positions.size() - 1);
	
	return positions[index];
}

position computer::shoot_without_wounded_ship() const
{
	int16_t index = random(empty_cells.size() - 1);
	return empty_cells[index];
}

//-------------------- public methods --------------------

computer::computer()
{
	empty_cells_reset();

	std::random_device rd;
	mt = std::mt19937(rd());
}

void computer::past_ships()
{
	bool ships_do_not_fit = true;
	while (ships_do_not_fit)
	{
		gr.reset();
		ships_do_not_fit = past_ship(4);
		for (int16_t i = 0; i < 2; ++i) ships_do_not_fit = past_ship(3);
		for (int16_t i = 0; i < 3; ++i) ships_do_not_fit = past_ship(2);
		for (int16_t i = 0; i < 4; ++i) ships_do_not_fit = past_ship(1);
		empty_cells_reset();
		std::sort(empty_cells.begin(), empty_cells.end());
	}
}

void computer::shoot(player& plr, bool& flag)
{
	Sleep(500);
	position shoot_position;
	if (wounded_ship.empty())
	{
		shoot_position = shoot_without_wounded_ship();
	}
	else
	{
		shoot_position = shoot_with_wounded_ship();
	}
	empty_cells.erase(std::find(empty_cells.begin(), empty_cells.end(), shoot_position));

	if (plr.get_grid()[shoot_position.first][shoot_position.second] == grid::Status::Ship)
	{
		plr.set_grid(shoot_position.first, shoot_position.second, grid::Status::WoundedShip);
		wounded_ship.push_back(shoot_position);
		std::sort(wounded_ship.begin(), wounded_ship.end());

		for (position pos : posible_positions())
		{
			if (plr.get_grid()[pos.first][pos.second] == grid::Status::Ship)
			{
				std::sort(wounded_ship.begin(), wounded_ship.end());
				return;
			}
		}

		wounded_ship.clear();
	}
	else
	{
		plr.set_grid(shoot_position.first, shoot_position.second, grid::Status::Bomb);
		flag = !flag;
	}
}