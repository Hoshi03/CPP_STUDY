#include<iostream>
using namespace std;

class Player {

public:
	virtual ~Player() {};
};

class Knight : public Player {

};

class Archer : public Player {

};

class Dog {

};

void printname(char* str) {
	cout << str << endl;
}

int main() {

	int hp = 100;
	int maxhp = 200;
	//float ratio = (float)hp / maxhp; // C��Ÿ���� ĳ����
	float ratio = static_cast<float>(hp) / maxhp;//���� ���� ���� ĳ����

	Player* p = new Player;
	Knight* k1 = static_cast<Knight*>(p); //��� ���輭 �ٿ�ĳ����
	Knight* k2 = dynamic_cast<Knight*>(p); // ��� ���迡�� �����ϰ� ����ȯ

	printname((char*)"ho"); //��������� ����ȯ �� ����
	printname(const_cast<char*>("ho")); // const_cast�� const ������ ����

	__int64 address = (__int64)k2; // ����
	__int64 address1 = reinterpret_cast<__int64>(k2); // ��� ���� ���� ������ ��ȯ

	Dog* dog = (Dog*)k2;
	Dog* dog2 = reinterpret_cast<Dog*>(k2);


	return 0;

}