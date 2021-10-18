#include "game.h"
#include "computer.h"
#include "human.h"
#include "menu.h"
#include "grid.h"

#include <iostream>
#include <string>

int main()
{
	computer comp1, comp2;
	human human1, human2;
	
	menu Menu({ "vs human","vs computer","exit" });
	bool Exit = false;

	while (!Exit)
	{
		Menu.show();

		if (Menu.get_choice() == 1)
		{
			game Game(human1, human2);
			Game.set_names();
			Game.play();
		}
		else if (Menu.get_choice() == 2)
		{
			game Game(human1, comp2);
			Game.set_first_name();
			Game.play();
		}
		else if (Menu.get_choice() == 3)
		{
			Exit = true;
		}
	}
}