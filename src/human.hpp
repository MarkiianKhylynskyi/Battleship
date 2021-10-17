#ifndef HUMAN_H
#define HUMAN_H

#include"player.hpp"

#include<functional>

class human : public player
{
private:
	std::function<grid()> func_past_ships;
	std::function<position()> func_shoot;
public:
	human(std::function<grid()> func_past_ships, std::function<position()> func_shoot);

	void past_ships() override;

	void shoot(player& plr, bool& flag) override;
};

#endif //HUMAN_H
