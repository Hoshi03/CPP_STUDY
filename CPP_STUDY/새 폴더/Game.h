#pragma once

class Player;//���� ����, Ŭ���� ���ðŶ�� ���� ���ָ� ������� ���� ���ص� ���� ����
class Field;

class Game
{
public:
	Game();
	~Game();

	void init();//�ʱ�ȭ
	void update();//�����Ӹ��� ������Ʈ

	void createplayer();
	
private:
	Player* _player;
	Field* _field;
};

