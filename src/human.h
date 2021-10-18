#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

#include <string>

class human : public player
{
public:
	human();

	void set_name(std::string name);

	void past_ships() override;

	void shoot(player& plr, bool& flag) override;	
};

#endif //HUMAN_H