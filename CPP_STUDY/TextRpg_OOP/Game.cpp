#include "Game.h"
#include <iostream>
#include "Player.h"
#include "Field.h"
using namespace std;
//파일 분할해서 생성자, 소멸자 작성

Game::Game() : _player(nullptr), _field(nullptr)
{

}

Game::~Game() 
{
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;
}

void Game::init() 
{
	_field = new Field;
}

void Game::update()
{
	if (_player == nullptr)
		createplayer();


	if (_player->isdead()) {
		delete _player;
		_player = nullptr;
		createplayer();
	}


	_field->update(_player);
}

void Game::createplayer()
{
	while (_player == nullptr)
	{
		cout << "------------------------------" << endl;
		cout << "캐릭터 생성!" << endl;
		cout << "1 - 기사 2 - 궁수 3 - 법사" << endl;
		cout << "------------------------------" << endl;

		cout << ">";
		int input = 0;
		cin >> input;

		if (input == PT_Knight)
		{
			_player = new Knight();
		}

		else if (input == PT_Archer)
		{
			_player = new Archer();
		}

		else if (input == PT_Mage)
		{
			_player = new Mage();
		}
	}

}
