#include <iostream>
using namespace std;

struct statinfo { //4바이트 변수 3개, 12바이트
	int hp;
	int atk;
	int def;
};

void enterlobby();
void createplayer(statinfo *playerinfo); // 포인터 없는 버전
void createmonster(statinfo* moninfo); // 포인터 사용한 버전
bool startbattle(statinfo * player, statinfo * monster);

int main() {
	enterlobby();
}

void enterlobby() {
	cout << "로비에 입장!" << endl;
	statinfo player;
	player.hp = 0xbbbbbbbb;
	player.atk = 0xbbbbbbbb;
	player.def = 0xbbbbbbbb;


	createplayer(&player);
	statinfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.atk = 0xbbbbbbbb;
	monster.def = 0xbbbbbbbb;

	createmonster(&monster);
	bool victory = startbattle(&player, &monster);

	if (victory == true)
		cout << "승리" << endl;
	else
		cout << "패배" << endl;
}

void createplayer(statinfo *playerinfo){
	cout << "플레이어 생성" << endl;
	playerinfo->hp = 40;
	playerinfo->atk = 8;
	playerinfo->def = 1;
}
void createmonster(statinfo* moninfo){
	cout << "몬스터 생성" << endl;
	moninfo->hp = 40;
	moninfo->atk = 8;
	moninfo->def = 1;
}

bool startbattle(statinfo* player, statinfo* monster) {
	while (true) {
		int damage = player->atk - monster->def;
		if (damage < 0) {
			damage = 0;
		}
		cout << "mon hp: " << monster->hp << endl;
		cout << "player hp: " << player->hp << endl;
		monster->hp -= damage;
		if (monster->hp < 0) {
			monster->hp = 0;
		}

		if (monster->hp == 0) {
			return true;
		}
		damage = monster->atk - player->def;
		if (damage < 0) {
			damage = 0;

		cout << "player hp: " << player->hp << endl;
		player->hp -= damage;
		if (player->hp < 0) {
			player->hp = 0;
		}
		if (player->hp == 0) {
			return false;
		}

		}
		

	}
}