#include<iostream>
using namespace std;

class marin {
public:
	static void setattack() {
		s_attack = 100;
	}

public:
	int _hp;
	static int s_attack; //설계 상으로만 존재

};

int generateid() {
	static int s_id = 1; // 처음 선언때 1로 초기화
	return s_id++; // 그 후 프로그램 끝날때까지 값 기억하면서 동작
}

int marin::s_attack = 0; // static으로 해논걸 전역변수로 선언

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