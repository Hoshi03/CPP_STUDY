#include "Monster.h"
#include <iostream>
using namespace std;

void Monster::printinfo() {
	cout << "-----------------------------" << endl;
	cout << "[몬스터 정보] " << "HP: " << _hp << " ATK: " << _attack << " DEF: " << _defence << endl;;
	cout << "-----------------------------" << endl;
}