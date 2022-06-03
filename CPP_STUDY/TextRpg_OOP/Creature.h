#pragma once
//플레이어와 몬스터 공통 부분을 작성할 클래스
enum CreatureType {
	CT_Player = 0,
	CT_Monster = 1
};

class Creature
{
public:
	Creature(int creaturetype) :
		_creaturetype(creaturetype), _hp(0), _attack(0), _defence(0) {

	}

	virtual ~Creature() {

	}

	virtual void printinfo() = 0;// 추상함수로 재정의 

	void onattacked(Creature* attacker);

	bool isdead() {
		return _hp <= 0;
	}

protected:
	int _creaturetype;
	int _hp;
	int _attack;
	int _defence;

};

