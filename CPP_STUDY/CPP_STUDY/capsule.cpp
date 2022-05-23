#include<iostream>
using namespace std;

class car {
public:
	void movehandle();
	void pushpedal();
	void opendoor();

protected:
	void disassemblecar();
	void runengine();
	void connectcircuit();

public:
};

class supercar : public car {
	void controller() {
		runengine();
	}
};

class buk {
public:
	void busuk() {
		cout << "“·" << endl;
	}
	void sethp(int hp) {
		_hp = hp;
		if (_hp < 50) {
			busukermode();
		}

	}
	int gethp(){
		return _hp;
	}

private:
	void busukermode() {
		cout << "°­ÇØÁü" << endl;
	}
private:
	int _hp = 100;
};

int main() {
	car kart;
	buk b;
	b.sethp(30);
}