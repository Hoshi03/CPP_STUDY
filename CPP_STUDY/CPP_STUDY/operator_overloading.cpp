#include<iostream>
using namespace std;

class pos {
public:

	pos operator+(const pos& arg) {// Ŭ�������� ���ϱ�
		pos position;
		position._x = _x + arg._x;
		position._y = _y + arg._y;

		return position;
	}
	pos operator+(int arg) { // Ŭ���� + ���� ����
		pos position;
		position._x = _x + arg;
		position._y = _y + arg;

		return position;
	}

	bool operator==(const pos &a) {
		return _x == a._x && _y == a._y; // if-else ������� �ʰ� ���ϸ����ε� T/F �Ǻ� ����
	}

	pos& operator= (int arg){
		_x = arg;
		_y = arg;
		return *this;
	}
	
	pos& operator++() {// ������ �������� ����Ҽ��� ������ �ڱ��ڽ������� �ϴ°� ����
		_x++;
		_y++;
		return *this;
	}

	pos operator++(int) {// ����, ���� pos&�� ���۷����� �����ع����� �������� ref�� �����ع���, ����
		pos ref = *this; // �����Ǳ� ���� ��
		_x++;
		_y++;
		return ref; 
	}


public:
	int _x;
	int _y;
};

pos operator+(int a, const pos &b) { // ���� ������ �Լ� ����, ���� + ������ ����
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
	pos3 = pos1.operator+(pos2); //���� ���� �ǹ�
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