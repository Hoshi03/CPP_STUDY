#include<iostream>
using namespace std;

//함수 구조 
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
void printinfo(const char* name, const statinfo& stat);// 뒤에 참조를 한 이유 - 값 복사 형식은 비효율적임, const를 쓴 이유 - 값 확인용이라 변하지 않을 거기 때문
void entergame(statinfo* player);
void createmonster(statinfo monster[], int count);
bool enterbattle(statinfo *player, statinfo *monster);

int main() {
	srand((unsigned)time(nullptr));
	enterlobby();
}

void enterlobby() {
	while (true) {
		print("로비 입장");
		statinfo player;
		createplayer(&player); // 포인터니 주소값 넘겨주기
		printinfo("player", player); // 참조니까 그냥 넘겨주기
		entergame(&player);
	}
}

void print(const char* msg) { //print 함수 만들기
	cout << "-----------------------------------------" << endl;
	cout << msg << endl;
	cout << "-----------------------------------------" << endl;
}

void createplayer(statinfo* player) {
	bool ready = false;
	while (ready == false)
	{
		print("1-기사 2-궁수 3-법사");
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

void printinfo(const char* name, const statinfo& stat) { // 앞에건 이름, 뒤에꺼는 레퍼런스
	cout << "-----------------------------------" << endl;
	cout << "stat - hp/atk/def " << stat.hp << " " << stat.atk << " " << stat.def << endl;
	cout << "-----------------------------------" << endl;
}

void entergame(statinfo* player) {
	const int moncount = 2;
	print("게임 입장!");
	while (true) {
		statinfo monster[moncount];
		createmonster(monster, moncount);

		for (int i = 0; i < moncount; i++) {
			printinfo("몬스터", monster[i]);
		}
		printinfo("플레이어", *player); //참조 형식에 포인터 값을 넣어야 되니 포인터 값을 꺼내주는 *를 사용

		print("1 - 1번몹 전투 2 - 2번몹 전투 3 - 런");

		int input;
		cin >> input;

		if (input == 1 || input == 2) {
			int index = input - 1;
			bool victory = enterbattle(player, &monster[index]); // monster[index]는 statinfo 구조체이기때문에 &을 넣어서 주소값을 넘겨줌!
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
			print("몬스터를 처치했습니다");
			return true;
		}

		damage = monster->atk - player->def;
		if (damage < 0)
			damage = 0;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		cout << "플레이어 상태: " << endl;
		printinfo("Player", *player);

		if (player->hp == 0)
		{
			print("Game Over");
			return false;
		}
	}
}


