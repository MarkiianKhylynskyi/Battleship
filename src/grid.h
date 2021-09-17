#ifndef MAP_H
#define MAP_H

#include<array>
#include<cstdint>

class grid
{
public:
	enum class Status
	{
		Empty,
		Bomb,
		Ship,
		WoundedShip
	};
	static const size_t MapSize = 10;
private:
	
	std::array<std::array<Status,MapSize>,MapSize> gr;
public:
	grid();

	const std::array<std::array<Status, MapSize>, MapSize>& get() const;

	void set(int16_t x, int16_t y, Status status);
};

#endif