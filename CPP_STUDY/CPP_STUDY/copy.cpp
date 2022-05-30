#include<iostream>
using namespace std;


class Pet {
public:
	Pet() {
		cout << "pet ����!" << endl;
	}

	~Pet() {
		cout << "pet �Ҹ�!" << endl;
	}

	Pet(const Pet& pet) {
		cout << "pet ����!" << endl;
	}
};

class Player {
public:
	Player() {
		cout << "player ������" << endl;
	}

	Player(const Player& player) {
		cout << "���� ������" << endl;
		_level = player._level;
 	}

	Player& operator=(const Player& player) {
		cout << "���� ���� ������" << endl;
		_level = player._level;
		return *this;
	}

public:
	int _level = 0;

};

class Knight : public Player
{
public:
	Knight() {
		//_pet = new Pet;
	}
	;
	~Knight() {
		//delete _pet;
	};

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet) { // ���� ������
		_hp = knight._hp;
		//_pet = new Pet(*knight._pet); //���� knight�� ������ �ִ� pet�� ���� ����, ���� Ÿ���� const�ϱ� *�� �� ���� �־���, ���� ����!
	}

	Knight& operator=(const Knight& knight) {//���� ���� ������
		_hp = knight._hp;
		_pet = knight._pet; // ��������� �Ҷ� �� �־������ �۵���
		Player::operator=(knight);

		//_pet = new Pet(*knight._pet); // ���� ����!
		return *this;
	}

public:
	int _hp = 100;
	Pet _pet;
};



int main() {
	//Pet* pet = new Pet();
	Knight knight;
	knight._hp = 200;

	
	//knight._pet = pet;

	//�Ѵ� ����������� ����
	cout << "���� ������!!!" << endl;
	//Knight knight2 = knight; 
	//Knight knight3(knight);

	cout << "���� ���� ������!!!" << endl;
	Knight knight3;
	knight3 = knight;
}