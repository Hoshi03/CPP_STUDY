#pragma once

class Player;
class Monster;

class Field
{
public:
	Field();
	~Field();
	void update(Player* player);
	void createmonster();

	void startbattle(Player* player);

private:
	Monster* _monster;

};

