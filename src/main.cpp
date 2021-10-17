#include <iostream>
#include <thread>
#include <cstdlib>

#include "computer.hpp"

#ifdef _WIN32
#include <windows.h>

// https://docs.microsoft.com/en-us/windows/console/clearing-the-screen
static void clrscr()
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SMALL_RECT scrollRect;
	COORD scrollTarget;
	CHAR_INFO fill;

	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	// Scroll the rectangle of the entire buffer.
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	// Scroll it upwards off the top of the buffer with a magnitude of the entire height.
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	// Fill with empty spaces with the buffer's default text attribute.
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	// Do the scroll
	ScrollConsoleScreenBuffer(hConsole, &scrollRect, NULL, scrollTarget, &fill);

	// Move the cursor to the top left corner too.
	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;

	SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);
}
#elif __linux__
static void clrscr()
{
	std::cout << "\033[H\033[2J\033[3J";
}
#endif


int main()
{
	computer first;
	first.past_ships();

	computer second;
	second.past_ships();

	bool game_continues = true, shoots_first_player = true;
	while (true)
	{
		clrscr();
		first.print();
		std::cout << std::endl;
		second.print();

		if (!game_continues)
			break;
		
		if (shoots_first_player)
		{
			first.shoot(second, shoots_first_player);
			game_continues = second.not_drowned_ships();
		}
		else
		{
			second.shoot(first, shoots_first_player);
			game_continues = first.not_drowned_ships();
		}
	}

	using namespace std::literals;
	std::this_thread::sleep_for(1700ms);

	if (shoots_first_player)
		std::cout << "First player wins" << std::endl;
	else
		std::cout << "Second player wins" << std::endl;

	return EXIT_SUCCESS;
}
