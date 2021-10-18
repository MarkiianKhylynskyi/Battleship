#ifndef MENU_H
#define MENU_H

#include <cstdint>
#include <vector>
#include <string>

class menu
{
public:
	menu(const std::vector<std::string> cases);

	void show();
	int16_t get_choice();
private:
	std::vector<std::string> cases;
	int16_t choice;
};

#endif //MENU_H