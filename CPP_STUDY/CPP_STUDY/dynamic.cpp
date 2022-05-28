#include<iostream>
using namespace std;

class monster {
public:
	int _x;
	int _y;
	int _hp;
};


int main() {
	void * pointer = malloc(sizeof(monster)); // 1000 바이트 만큼 할당하고 시작주소를 pointer로 뱉어줌 
	monster* m1 = (monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	free(pointer);
	pointer = nullptr; // uaf 방지
	m1 = nullptr; // uaf 방지

	monster* m2 = new monster; // new delete
	m2->_hp = 200;
	m2->_x = 3;
	m2->_y = 5;
	delete m2;	

	monster* m3 = new monster[5]; // new[], delete[]

	monster* m4 = (m3 + 1); // m3에 5마리 분량을 할당했기에 가능
	monster* m5 = (m3+ 2);
	delete[] m3;

}