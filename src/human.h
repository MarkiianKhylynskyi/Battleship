#ifndef HUMAN_H
#define HUMAN_H

#include"player.h"

class human : public player
{
private:
public:

	void past_ships() override;

	void shoot(player& plr, bool& flag) override;
};

#endif