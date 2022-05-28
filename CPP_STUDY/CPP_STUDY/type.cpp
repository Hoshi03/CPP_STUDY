#include<iostream>
using namespace std;

class knight {
public:
	int _hp = 10;
};

class dog {
public:
	int _age = 1;
	int _cute = 10;
public:
	dog(){

	}
	dog(const knight& knight) {// 타입 변환 생성자
		_age = knight._hp;
	}

	//타입 변환 연산자
	operator knight() {
		return (knight)(*this); // 자기 자신을 knight 클래스로 변환
	}
};

class bulldog : public dog {
public:
	bool french;

public:
};

int main() {
	{
		int a = 123456;
		float b = (float)a; // 값 변환 int를 float로 변환하기
		float c = (float&)a; // 참조 타입 변환
		//cout << b << endl;
		//cout << c << endl;
	}

	{
		int d = 123;
		float e = d; //암시적 변환
		cout << e << endl;
		int* f = (int*)d;
		cout << *f << endl;
	}

	{
		knight k1;
		dog d1 = (dog)k1; // 클래스 변환을 통해서 억지로 넣음
		knight k2 = d1; // 
	}

	{
		//연관없는 클래스 사이에서 참조 타입 변환하기
		knight  k1;
		dog& doggy = (dog&)k1; //참조 타입변환으로 

	}

	{
		//상속 관계 클래스 값 타입 변환
		//자식 클래스에서 부모 클래스로 가기 - 불가능
		dog d1;
		//bulldog d2 = d1; 

		//부모 클래스에서 자식 클래스로 가기 - 가능
		bulldog d3;
		dog d4 = d3;
	}

	{
		//상속 관계 클래스 참조 타입 변환
		
		dog d5;
		bulldog& d6 = (bulldog&)d5;


		
		// 무난하가 가능
		bulldog d7;
		dog& d8 = d7;
	}


}