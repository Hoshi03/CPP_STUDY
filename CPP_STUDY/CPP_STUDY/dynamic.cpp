#include<iostream>
using namespace std;

class monster {
public:
	int _x;
	int _y;
	int _hp;
};


int main() {
	void * pointer = malloc(sizeof(monster)); // 1000 ����Ʈ ��ŭ �Ҵ��ϰ� �����ּҸ� pointer�� ����� 
	monster* m1 = (monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	free(pointer);
	pointer = nullptr; // uaf ����
	m1 = nullptr; // uaf ����

	monster* m2 = new monster; // new delete
	m2->_hp = 200;
	m2->_x = 3;
	m2->_y = 5;
	delete m2;	

	monster* m3 = new monster[5]; // new[], delete[]

	monster* m4 = (m3 + 1); // m3�� 5���� �з��� �Ҵ��߱⿡ ����
	monster* m5 = (m3+ 2);
	delete[] m3;

}