#include<iostream>
using namespace std;


class player
{
	public:
		player() {
			cout << "player ������ ȣ��" << endl;
		}
		player(int hp) {
			_hp = hp;
			_attack = 0;
			_defence = 0;
			cout << "hp ������ player ������" << endl;
		}

		~player() {
			cout << "player �Ҹ��� ȣ��" << endl;
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
		cout << "knight ������ ȣ��" << endl;
	}
	knight(int stamina):player(100) { // knight�� ���¹̳ʸ� �������ִ� ��Ÿ �����ڸ� �����Ҷ� �÷��̾ ü���� �������ִ� ��Ÿ �����ڷ� ���� ':' �־ �����!
		int _stamina = stamina;
		cout << "knight ���¹̳� ���� ������ ȣ��" << endl;
	}
	~knight() {
		cout << "knight �Ҹ��� ȣ��" << endl;
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