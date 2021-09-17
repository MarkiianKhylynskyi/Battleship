#ifndef PAIR_H
#define PAIR_H

#include<cstdint>

struct pair
{
	int16_t x;
	int16_t y;

	pair() = default;

	pair(int16_t x, int16_t y);
};

#endif