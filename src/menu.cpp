#include "menu.h"

#include <iostream>

int16_t menu::get_choice()
{
	return choice;
}

menu::menu(const std::vector<std::string> cases)
{
	this->cases = cases;
}

void menu::show()
{
	system("cls");
	std::cout << std::endl;

	for (int16_t i = 0; i < cases.size(); ++i)
	{
		std::cout << i + 1 << ". " << cases[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << ": ";
	std::cin >> choice;
}