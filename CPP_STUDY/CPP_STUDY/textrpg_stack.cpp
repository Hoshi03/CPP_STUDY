#include<iostream>
using namespace std;

//�Լ� ���� 
// - enterlobby
// -- createplayer -- entergame
// --- createmonsters --- enterbattle

enum playertype {
	knight = 1,
	archer = 2,
	mage = 3
};

enum monstertype {
	slime = 1,
	orc = 2,
	skeleton = 3
};

struct statinfo {
	int atk = 0;
	int def = 0;
	int hp = 0;
};

void print(const char* msg);
void enterlobby();
void createplayer(statinfo* player);
void printinfo(const char* name, const statinfo& stat);// �ڿ� ������ �� ���� - �� ���� ������ ��ȿ������, const�� �� ���� - �� Ȯ�ο��̶� ������ ���� �ű� ����
void entergame(statinfo* player);
void createmonster(statinfo monster[], int count);
bool enterbattle(statinfo *player, statinfo *monster);

int main() {
	srand((unsigned)time(nullptr));
	enterlobby();
}

void enterlobby() {
	while (true) {
		print("�κ� ����");
		statinfo player;
		createplayer(&player); // �����ʹ� �ּҰ� �Ѱ��ֱ�
		printinfo("player", player); // �����ϱ� �׳� �Ѱ��ֱ�
		entergame(&player);
	}
}

void print(const char* msg) { //print �Լ� �����
	cout << "-----------------------------------------" << endl;
	cout << msg << endl;
	cout << "-----------------------------------------" << endl;
}

void createplayer(statinfo* player) {
	bool ready = false;
	while (ready == false)
	{
		print("1-��� 2-�ü� 3-����");
		cout << ">";
		int input;
		cin >> input;
		switch (input)
		{
			case knight:
				player->hp = 100;
				player->def = 15;
				player->atk = 10;
				ready = true;
			case archer:
				player->hp = 80;
				player->def = 10;
				player->atk = 20;
				ready = true;
			case mage:
				player->hp = 50;
				player->def = 5;
				player->atk = 40;
				ready = true;
		}
	}
}

void printinfo(const char* name, const statinfo& stat) { // �տ��� �̸�, �ڿ����� ���۷���
	cout << "-----------------------------------" << endl;
	cout << "stat - hp/atk/def " << stat.hp << " " << stat.atk << " " << stat.def << endl;
	cout << "-----------------------------------" << endl;
}

void entergame(statinfo* player) {
	const int moncount = 2;
	print("���� ����!");
	while (true) {
		statinfo monster[moncount];
		createmonster(monster, moncount);

		for (int i = 0; i < moncount; i++) {
			printinfo("����", monster[i]);
		}
		printinfo("�÷��̾�", *player); //���� ���Ŀ� ������ ���� �־�� �Ǵ� ������ ���� �����ִ� *�� ���

		print("1 - 1���� ���� 2 - 2���� ���� 3 - ��");

		int input;
		cin >> input;

		if (input == 1 || input == 2) {
			int index = input - 1;
			bool victory = enterbattle(player, &monster[index]); // monster[index]�� statinfo ����ü�̱⶧���� &�� �־ �ּҰ��� �Ѱ���!
			if (victory == false)
				break;
		}
	}
}

void createmonster(statinfo monster[], int count) {
	for (int i = 0; i < count; i++) {
		int randvalue = 1 + (rand() % 3);

		switch (randvalue)
		{
		case slime:
			monster[i].hp = 30;
			monster[i].atk = 5;
			monster[i].def = 1;

		case orc:
			monster[i].hp = 40;
			monster[i].atk = 7;
			monster[i].def = 3;
		case skeleton:
			monster[i].hp = 50;
			monster[i].atk = 10;
			monster[i].def = 5;
		}
	}
}

bool enterbattle(statinfo* player, statinfo* monster) {
	while (true)
	{
		int damage = player->atk - monster->def;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		printinfo("Monster", *monster);

		if (monster->hp == 0)
		{
			print("���͸� óġ�߽��ϴ�");
			return true;
		}

		damage = monster->atk - player->def;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "�÷��̾� ����: " << endl;
		printinfo("Player", *player);

		if (player->hp == 0)
		{
			print("Game Over");
			return false;
		}
	}
}


