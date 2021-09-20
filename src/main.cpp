#include"main.h"

int main()
{
	/*grid Grid;
	Grid.set(2, 3, grid::Status::Ship);
	Grid.set(2, 4, grid::Status::Ship);
	Grid.set(2, 5, grid::Status::Ship);
	Grid.set(2, 6, grid::Status::Ship);
	Grid.set(5, 3, grid::Status::Bomb);
	Grid.print();*/

	computer comp1,comp2;
	game Game(comp1, comp2);
	Game.play();
}