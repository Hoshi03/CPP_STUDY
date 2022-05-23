#include<iostream>
using namespace std;

//다형성 

class player {
public:
	virtual void move() {
		cout << "move player!" << endl;
	}
	player() {
		//cout << "기본 생성자";
	}

	void move(int hp) {
		cout << "move player! (int)" << endl;
	}
public:
	int _hp;
};

class mage : public player {

	
public:
	int _mp;
};

class knight : public player {
public:
	virtual void move() {
		cout << "move knight!" << endl;
	}
public:
	int _stamina;
};

void moveplayer(player* player) {
	player->move();
}

void moveknight(knight* knight) {
	knight->move();
}

int main() {
	player a;
	knight b;
	moveplayer(&a);
	moveplayer(&b);
}