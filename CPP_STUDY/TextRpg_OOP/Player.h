#pragma once
#include "Creature.h"

enum PlayerType {
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};


class Player : public Creature
{
public:

	Player(int playerType) : Creature(CT_Player), _playerType(playerType) {

	}

	virtual ~Player() { // 부모 클래스 소멸자는 버추얼로!

	}

	virtual void printinfo();

protected:
	int _playerType;

};

class Knight : public Player {
public:
	Knight() : Player(PT_Knight) { // 부모에서 만든 생성자 상속해서	 사용!
		_hp = 150;
		_attack = 10;
		_defence = 5;
	}

};

class Archer : public Player {
public:
	Archer() : Player(PT_Archer) {
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player {
public:
	Mage() : Player(PT_Mage) {
		_hp = 50;
		_attack = 25;
		_defence = 0;
	}
};
