#include<iostream>
using namespace std;


class player
{
	public:
		player() {
			cout << "player 생성자 호출" << endl;
		}
		player(int hp) {
			_hp = hp;
			_attack = 0;
			_defence = 0;
			cout << "hp 지정한 player 생성자" << endl;
		}

		~player() {
			cout << "player 소멸자 호출" << endl;
		}
		void move();
		void attack();
		void die();

	public:
		int _hp;
		int _attack;
		int _defence;
};

class knight : public player {
public:
	knight() {
		cout << "knight 생성자 호출" << endl;
	}
	knight(int stamina):player(100) { // knight에 스태미너를 지정해주는 기타 생성자를 생성할때 플레이어도 체력을 지정해주는 기타 생성자로 생성 ':' 넣어서 만들기!
		int _stamina = stamina;
		cout << "knight 스태미나 지정 생성자 호출" << endl;
	}
	~knight() {
		cout << "knight 소멸자 호출" << endl;
	}
public:
	int _stamina;
};

class mage : public player {
public:
};


int main() {
	knight k1(10);

}