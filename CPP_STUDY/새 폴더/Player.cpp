#include "Player.h"
#include <iostream>
using namespace std;

void Player::printinfo() 
{
	cout << "-----------------------------" << endl;
	cout << "[�÷��̾� ����] " << "HP: " << _hp << " ATK: " << _attack << " DEF: " << _defence << endl;;
	cout << "-----------------------------" << endl;
}