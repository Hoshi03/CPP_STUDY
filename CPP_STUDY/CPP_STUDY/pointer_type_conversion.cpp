#include<iostream>
using namespace std;

class knight {
public:
	int _hp = 0;
};


class item {
public:
	item() {
		cout << "item ȣ��" << endl;
	}
	item(int itemtype) : _itemtype(itemtype){
	
	}

	item(const item& item) {
		cout << "item ���� ������" << endl;
	}
	
	virtual ~item() { // �θ𿡼� �Ҹ��ڿ� virtual�� �ٿ��ָ� �����Ҷ� ����� ���� ��������!
		cout << "item �Ҹ���" << endl;
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
	////�����Ϳ� �� ���� ��
	////stack �������� ȣ��, item Ŭ���� ���� �� 4096+8 ����Ʈ��ŭ ����
	//item it1;

	////�̰͵� stack �������� ȣ�������� �����ͱ� ������ �ּ� ũ���� 4~8 ����Ʈ�� �������� ����
	//item* it2 = new item;

	//testitem(it1);
	//testitem(*it2);

	//testitemptr(&it1);
	//testitemptr(it2);
	//}

	//{
	////�迭
	//	//���� �޸𸮿� item �� 100�� �־��� ����, item 100���� ������ ����� ���⿡ �׸�ŭ ������ ������
	//	cout << "----------------------------------------------------------------------" << endl;
	//	item item3[100] = {}; 

	//	//�������� ����Ű�� �����Ͱ� 100�� �ִ� ����, �����δ� item�� ���� ���� ����
	//	cout << "----------------------------------------------------------------------" << endl;
	//	item* item4[100] = {};

	//}

	//{
	//	knight* k1 = new knight;
	//	item* it1 = (item*)k1; // ��������� ������ ��ȯ  ����
	//	delete k1;
	//}


	////�θ� -> �ڽ� ��ȯ �׽�Ʈ
	//{
	//	item* item1 = new item;

	//	//weapon* weapon1 = item1; // �θ� �ڽ� �������� �Ͻ������� �θ� -> �ڽ� ��ȯ�� �Ұ���


	//	delete item1;
	//}

	////�ڽ� -> �θ� ��ȯ �׽�Ʈ
	//{
	//	weapon* wp1 = new weapon;
	//	item* item2 = wp1; // �ڽ� -> �θ� ��ȯ�� �Ͻ������� ����
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

		delete it; // �̷��� �ϸ� �ڽ� Ŭ������ �Ҹ��ڴ� ȣ���� ���� ����, virtual�� ���̸� �ڽ� Ŭ�������� ����!!!!!


		//// �̷��� �ڽ� Ŭ������ �� ��ȯ�� �ؼ� ������ �ؾ� �޸� �������� ������ ����
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