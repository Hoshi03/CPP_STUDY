#include<iostream>
using namespace std;

class inventory {
public:
	inventory() { cout << "inventory" << endl; }
	inventory(int size) { cout << "inventory - int" << endl; _size = size; }
	~inventory(){ cout << "remove inventory" << endl; }
public:
	int _size = 10;
};

class player {
public:
	player() {}
	player (int id) {

		cout << "player - int" << endl;
	}

};

class knight:public player{
public:
	knight() :player(1), _hp(100) , _inventory(100) // �ʱ�ȭ ����Ʈ�� ���!
	{
		//int _hp = 10;// ������ ������ �ʱ�ȭ
		cout << "���� hp = " << _hp << endl;
	}

public:
	int _hp;
	inventory _inventory;
};


int main() {
	knight k1;
}