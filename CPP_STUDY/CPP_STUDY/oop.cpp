#include<iostream>
using namespace std;

class knight {

public://멤버 함수
	knight() { //기본 생성자
		cout << "기본 생성자 호출" << endl;
		_hp = 100;
		_atk = 10;
		_posY = 0;
		_posX = 0;
	}
	~knight() { //기본 소멸자
		cout << "기본 소멸자 호출" << endl;
	}
	knight(int hp) { //기타 생성자, 기타 생성자에서 타입 하나만 받으면 타입 변환 생성자
		cout << "인자 생성자 호출" << endl;
		_hp = hp;
		_atk = 10;
		_posY = 0;
		_posX = 0;
	}
	knight(const knight& knight) { //복사 생성자 - 자기 자신의 클래스 레퍼런스 타입을 인자로 받음, 작성하지 않아도 암시적으로 이렇게 생성 되어있음
		cout << "복사 생성자 호출" << endl;
		_hp = knight._hp;
		_atk = knight._atk;
		_posY = knight._posY;
		_posX = knight._posX;
	}



	void move(int y, int x);
	void attack();
	void die() {// 클래스 안에서도 구현부 작성 가능
		_hp = 0;
		cout << "die" << endl;
	}

public://멤버 변수
	int _hp;
	int _atk;
	int _posX;
	int _posY;
};

void knight::move(int y, int x) {// 멤버 함수
	_posY = y;
	_posX = x;
	cout << "move" << endl;
}

void knight::attack() {
	cout << "attack : " << _atk << endl;
}

int main() {
	knight k1; //instatiate 객체 만들기

	k1.move(2, 2);
	k1.die();
	k1.attack();

	knight k3 = k1; //복사 생성자

	knight k4; // 기본 생성자
	k4 = k1; // 복사

	knight k5;
	k5 = 1;// x타입 변환
}