#include<iostream>
using namespace std;

class knight {

public://��� �Լ�
	knight() { //�⺻ ������
		cout << "�⺻ ������ ȣ��" << endl;
		_hp = 100;
		_atk = 10;
		_posY = 0;
		_posX = 0;
	}
	~knight() { //�⺻ �Ҹ���
		cout << "�⺻ �Ҹ��� ȣ��" << endl;
	}
	knight(int hp) { //��Ÿ ������, ��Ÿ �����ڿ��� Ÿ�� �ϳ��� ������ Ÿ�� ��ȯ ������
		cout << "���� ������ ȣ��" << endl;
		_hp = hp;
		_atk = 10;
		_posY = 0;
		_posX = 0;
	}
	knight(const knight& knight) { //���� ������ - �ڱ� �ڽ��� Ŭ���� ���۷��� Ÿ���� ���ڷ� ����, �ۼ����� �ʾƵ� �Ͻ������� �̷��� ���� �Ǿ�����
		cout << "���� ������ ȣ��" << endl;
		_hp = knight._hp;
		_atk = knight._atk;
		_posY = knight._posY;
		_posX = knight._posX;
	}



	void move(int y, int x);
	void attack();
	void die() {// Ŭ���� �ȿ����� ������ �ۼ� ����
		_hp = 0;
		cout << "die" << endl;
	}

public://��� ����
	int _hp;
	int _atk;
	int _posX;
	int _posY;
};

void knight::move(int y, int x) {// ��� �Լ�
	_posY = y;
	_posX = x;
	cout << "move" << endl;
}

void knight::attack() {
	cout << "attack : " << _atk << endl;
}

int main() {
	knight k1; //instatiate ��ü �����

	k1.move(2, 2);
	k1.die();
	k1.attack();

	knight k3 = k1; //���� ������

	knight k4; // �⺻ ������
	k4 = k1; // ����

	knight k5;
	k5 = 1;// xŸ�� ��ȯ
}