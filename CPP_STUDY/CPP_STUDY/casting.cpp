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
	//float ratio = (float)hp / maxhp; // C스타일의 캐스팅
	float ratio = static_cast<float>(hp) / maxhp;//위에 것을 정적 캐스팅

	Player* p = new Player;
	Knight* k1 = static_cast<Knight*>(p); //상속 관계서 다운캐스팅
	Knight* k2 = dynamic_cast<Knight*>(p); // 상속 관계에서 안전하게 형변환

	printname((char*)"ho"); //명시적으로 형변환 한 버전
	printname(const_cast<char*>("ho")); // const_cast로 const 제거한 버전

	__int64 address = (__int64)k2; // 땡깡
	__int64 address1 = reinterpret_cast<__int64>(k2); // 상관 없는 것을 강제로 변환

	Dog* dog = (Dog*)k2;
	Dog* dog2 = reinterpret_cast<Dog*>(k2);


	return 0;

}