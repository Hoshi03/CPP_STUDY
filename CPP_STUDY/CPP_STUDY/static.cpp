#include<iostream>
using namespace std;

class marin {
public:
	static void setattack() {
		s_attack = 100;
	}

public:
	int _hp;
	static int s_attack; //���� �����θ� ����

};

int generateid() {
	static int s_id = 1; // ó�� ���� 1�� �ʱ�ȭ
	return s_id++; // �� �� ���α׷� ���������� �� ����ϸ鼭 ����
}

int marin::s_attack = 0; // static���� �س�� ���������� ����

int main() {
	marin m1;
	marin::s_attack = 6;
	m1._hp = 40;
	marin m2;
	m2._hp = 40;
	m2.s_attack = 7;
	marin::setattack();

	cout << m1.s_attack << endl;
	cout << m2.s_attack << endl;

	cout << generateid() << endl;
	cout << generateid() << endl;
	cout << generateid() << endl;
}