#include <iostream>
using namespace std;

void enterlobby();
void selectplayer();
void enterfield();
void monster();

enum playertype {
	pt_ad = 1,
	pt_ap = 2
};

enum montype {
	mt_slime = 1,
	mt_orc = 2,
	mt_skeleton = 3
};

int playertype;
int hp;
int atk;
int def;

int montype;
int monhp;
int monatk;
int mondef;

int main(){
	srand(time(0));//랜덤 시드 설정
	enterlobby();
}

void enterlobby() {
	while (true) {
		cout << "---------------------------" << endl;
		cout << "로비 입장" << endl;
		cout << "---------------------------" << endl;
		selectplayer();
	int input;
	cin >> input;
	if (input == 1) {
		enterfield();
	}
	else{
		cout << "게임 종료" << endl;
		return;
	}
	}
}

void selectplayer() {
	while (true)
	{
		cout << "---------------------------" << endl;
		cout << "ad/ap 1 - ad, 2 - ap" << endl;
		cout << "---------------------------" << endl;
		cin >> playertype;
		if (playertype == 1) {
			cout << "ad!" << endl;
			hp = 150;
			atk = 10;
			def = 5;
			break;
			
		}
		else if (playertype == 2) {
			cout << "ap!" << endl;
			hp = 50;
			atk = 35;
			def = 10;
			break;
		}
	}
}

void enterfield() {
	while (true) {
		cout << "---------------------------" << endl;
		cout << "필드 입장" << endl;
		cout << "---------------------------" << endl;

		cout << "player state" << hp << "/" << atk << "/" << def << "/" <<  endl;

		monster();
	}
}

void monster() {
	montype = (rand() % 3) + 1;
	switch (montype)
	{
	case mt_slime:
		cout << "슬라임 생성 15/5/0 " << endl;
		monhp = 15;
		monatk = 5;
		mondef = 0;
		break;
	case mt_orc:
		cout << "오크 생성 30/10/5" << endl;
		monhp = 30;
		monatk = 10;
		mondef = 5;
		break;
	case mt_skeleton:
		cout << "스켈레톤 생성 50/15/10" << endl;
		monhp = 50;
		monatk = 15;
		mondef = 10;
		break;
	}
}