#include<iostream>
using namespace std;

class knight {
public:
	int _hp = 0;
};


class item {
public:
	item() {
		cout << "item 호출" << endl;
	}
	item(int itemtype) : _itemtype(itemtype){
	
	}

	item(const item& item) {
		cout << "item 복사 생성자" << endl;
	}
	
	virtual ~item() { // 부모에서 소멸자에 virtual을 붙여주면 삭제할때 상당히 많이 편해진다!
		cout << "item 소멸자" << endl;
	}
public:
	int _itemtype = 0;
	int _itemdb = 0;
	char dummy[4096] = {};
};

enum itemtype
{
	it_weapon = 1,
	it_armor = 2,
};

class weapon : public item {

public:
	weapon() : item(it_weapon){
		cout << "weapon()" << endl;
	}

	~weapon() {
		cout << "~weapon()" << endl;

	}
};

class armor : public item {

public:
	armor() : item(it_armor) {
		cout << "armor()" << endl;
	}

	~armor() {
		cout << "~armor()" << endl;
	}
};

void testitem(item item) {

}

void testitemptr(item* item) {
	cout << "ptr" << endl;
}



int main() {

	//{
	////포인터와 값 복사 비교
	////stack 영역에서 호출, item 클래스 내부 값 4096+8 바이트만큼 차지
	//item it1;

	////이것도 stack 영역에서 호출하지만 포인터기 때문에 주소 크기인 4~8 바이트만 고정으로 차지
	//item* it2 = new item;

	//testitem(it1);
	//testitem(*it2);

	//testitemptr(&it1);
	//testitemptr(it2);
	//}

	//{
	////배열
	//	//스택 메모리에 item 을 100개 넣어준 버전, item 100개가 실제로 만들어 졋기에 그만큼 공간을 차지함
	//	cout << "----------------------------------------------------------------------" << endl;
	//	item item3[100] = {}; 

	//	//아이템을 가르키는 포인터가 100개 있는 버전, 실제로는 item이 없을 수도 있음
	//	cout << "----------------------------------------------------------------------" << endl;
	//	item* item4[100] = {};

	//}

	//{
	//	knight* k1 = new knight;
	//	item* it1 = (item*)k1; // 명시적으로 포인터 변환  가능
	//	delete k1;
	//}


	////부모 -> 자식 변환 테스트
	//{
	//	item* item1 = new item;

	//	//weapon* weapon1 = item1; // 부모 자식 관계지만 암시적으로 부모 -> 자식 변환은 불가능


	//	delete item1;
	//}

	////자식 -> 부모 변환 테스트
	//{
	//	weapon* wp1 = new weapon;
	//	item* item2 = wp1; // 자식 -> 부모 변환은 암시적으로 가능
	//}


	srand((unsigned int)time(0));


	item* inventory[20] = {};
	for (int i = 0; i < 20; i++) {
		int randvalue = rand() % 2;
		switch (randvalue)
		{
		case 0:
			inventory[i] = new weapon(); 
			break;
		case 1:
			inventory[i] = new armor();
		}
	}

	for (int i = 0; i < 20; i++) {
		item* it = inventory[i];
		if (it == nullptr)
			continue;

		delete it; // 이렇게 하면 자식 클래스의 소멸자는 호출이 되지 않음, virtual을 붙이면 자식 클래스에서 삭제!!!!!


		//// 이렇게 자식 클래스로 형 변환을 해서 삭제를 해야 메모리 누수없이 완전히 삭제
		//if (it->_itemtype == it_weapon) {
		//	weapon* wep = (weapon*)it;
		//	delete wep;
		//}

		//else {
		//	armor* arm = (armor*)it;
		//	delete arm;
		//}

		
	}



}