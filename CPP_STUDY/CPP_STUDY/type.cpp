#include<iostream>
using namespace std;

class knight {
public:
	int _hp = 10;
};

class dog {
public:
	int _age = 1;
	int _cute = 10;
public:
	dog(){

	}
	dog(const knight& knight) {// Ÿ�� ��ȯ ������
		_age = knight._hp;
	}

	//Ÿ�� ��ȯ ������
	operator knight() {
		return (knight)(*this); // �ڱ� �ڽ��� knight Ŭ������ ��ȯ
	}
};

class bulldog : public dog {
public:
	bool french;

public:
};

int main() {
	{
		int a = 123456;
		float b = (float)a; // �� ��ȯ int�� float�� ��ȯ�ϱ�
		float c = (float&)a; // ���� Ÿ�� ��ȯ
		//cout << b << endl;
		//cout << c << endl;
	}

	{
		int d = 123;
		float e = d; //�Ͻ��� ��ȯ
		cout << e << endl;
		int* f = (int*)d;
		cout << *f << endl;
	}

	{
		knight k1;
		dog d1 = (dog)k1; // Ŭ���� ��ȯ�� ���ؼ� ������ ����
		knight k2 = d1; // 
	}

	{
		//�������� Ŭ���� ���̿��� ���� Ÿ�� ��ȯ�ϱ�
		knight  k1;
		dog& doggy = (dog&)k1; //���� Ÿ�Ժ�ȯ���� 

	}

	{
		//��� ���� Ŭ���� �� Ÿ�� ��ȯ
		//�ڽ� Ŭ�������� �θ� Ŭ������ ���� - �Ұ���
		dog d1;
		//bulldog d2 = d1; 

		//�θ� Ŭ�������� �ڽ� Ŭ������ ���� - ����
		bulldog d3;
		dog d4 = d3;
	}

	{
		//��� ���� Ŭ���� ���� Ÿ�� ��ȯ
		
		dog d5;
		bulldog& d6 = (bulldog&)d5;


		
		// �����ϰ� ����
		bulldog d7;
		dog& d8 = d7;
	}


}