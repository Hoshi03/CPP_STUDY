#pragma once

class Player;//전방 선언, 클래스 나올거라고 선언만 해주면 헤더파일 삽입 안해도 빌드 가능
class Field;

class Game
{
public:
	Game();
	~Game();

	void init();//초기화
	void update();//프레임마다 업데이트

	void createplayer();
	
private:
	Player* _player;
	Field* _field;
};

