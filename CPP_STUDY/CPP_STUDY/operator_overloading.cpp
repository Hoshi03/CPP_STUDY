#include<iostream>
using namespace std;

class pos {
public:

	pos operator+(const pos& arg) {// 클래스끼리 더하기
		pos position;
		position._x = _x + arg._x;
		position._y = _y + arg._y;

		return position;
	}
	pos operator+(int arg) { // 클래스 + 숫자 연산
		pos position;
		position._x = _x + arg;
		position._y = _y + arg;

		return position;
	}

	bool operator==(const pos &a) {
		return _x == a._x && _y == a._y; // if-else 사용하지 않고 리턴만으로도 T/F 판별 가능
	}

	pos& operator= (int arg){
		_x = arg;
		_y = arg;
		return *this;
	}
	
	pos& operator++() {// 전위는 연속으로 사용할수도 있으니 자기자신참조로 하는게 좋음
		_x++;
		_y++;
		return *this;
	}

	pos operator++(int) {// 후위, 여길 pos&로 레퍼런스를 전달해버리면 지역변수 ref를 전달해버림, 위험
		pos ref = *this; // 증가되기 이전 값
		_x++;
		_y++;
		return ref; 
	}


public:
	int _x;
	int _y;
};

pos operator+(int a, const pos &b) { // 전역 연산자 함수 버전, 숫자 + 연산자 버전
	pos position;
	position._x = a + b._x;
	position._y = a + b._y;

	return position;
}

int main() {
	pos pos1;
	pos1._x = 0;
	pos1._y = 0;

	pos pos2;
	pos2._x = 1;
	pos2._y = 1;

	pos pos3 = pos1 + pos2;
	pos3 = pos1.operator+(pos2); //둘이 같은 의미
	pos pos4 = pos3 + 1;
	pos pos5 = 1 + pos4;

	bool issame = pos4 == pos5;

	pos pos6;
	pos6 = 5;
	pos pos7;
	pos7 = (pos6 = 6);

	pos7 = ++pos6;
	pos7 = pos6++;
	pos5 = pos7;

	return 0;
}