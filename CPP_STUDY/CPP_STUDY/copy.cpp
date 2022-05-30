#include<iostream>
using namespace std;


class Pet {
public:
	Pet() {
		cout << "pet 생성!" << endl;
	}

	~Pet() {
		cout << "pet 소멸!" << endl;
	}

	Pet(const Pet& pet) {
		cout << "pet 복사!" << endl;
	}
};

class Player {
public:
	Player() {
		cout << "player 생성자" << endl;
	}

	Player(const Player& player) {
		cout << "복사 생성자" << endl;
		_level = player._level;
 	}

	Player& operator=(const Player& player) {
		cout << "복사 대입 연산자" << endl;
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

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet) { // 복사 생성자
		_hp = knight._hp;
		//_pet = new Pet(*knight._pet); //기존 knight가 가지고 있는 pet을 복사 생성, 참조 타입이 const니까 *을 찍어서 값을 넣어줌, 깊은 복사!
	}

	Knight& operator=(const Knight& knight) {//복사 대입 연산자
		_hp = knight._hp;
		_pet = knight._pet; // 명시적으로 할땐 다 넣어줘야지 작동함
		Player::operator=(knight);

		//_pet = new Pet(*knight._pet); // 깊은 복사!
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

	//둘다 같은방법으로 복사
	cout << "복사 생성자!!!" << endl;
	//Knight knight2 = knight; 
	//Knight knight3(knight);

	cout << "복사 대입 연산자!!!" << endl;
	Knight knight3;
	knight3 = knight;
}