#pragma once
//�÷��̾�� ���� ���� �κ��� �ۼ��� Ŭ����
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

	virtual void printinfo() = 0;// �߻��Լ��� ������ 

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

