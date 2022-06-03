#include "Field.h"
#include <stdlib.h>
#include "Monster.h"
#include "Player.h"

Field:: Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr) {
		delete _monster;
	}
}

void Field::createmonster()
{
	int randvalue = 1 + rand() % 3;
	switch (randvalue)
	{
	case MT_SLIME:
		_monster = new Slime();
	case MT_ORC:
		_monster = new Orc();
	case MT_SKELETON:
		_monster = new Skeleton();
	}
}

void Field::update(Player* player) {
	if (_monster == nullptr)
		createmonster();
	startbattle(player);
}


void Field::startbattle(Player * player)
{
	while (true)
	{
		player->printinfo();
		_monster->printinfo();

		//플레이어 몬스터 공격
		_monster->onattacked(player);

		if (_monster->isdead()) {
			_monster->printinfo();
			delete _monster;
			_monster = nullptr;
			break; // 다시 while loop로 돌아가기
		}

		//몬스터 플레이어 공격
		player->onattacked(_monster);
		if (player->isdead()) {
			player->printinfo();
			break; // 다시 while loop로 돌아가기
			//플레이어는 player에서 관리하므로 여기서 삭제 안함
		}




	}
}
