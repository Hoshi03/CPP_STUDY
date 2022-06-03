#include<iostream>
using namespace std;
#include "Game.h"

int main() 
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.init();

	while (true)
	{
		game.update();
	}
}