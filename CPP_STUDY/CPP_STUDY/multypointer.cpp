#include<iostream>
using namespace std;

void setmessage(const char * a) {
	a = "bye";
}

void setmessage(const char** a) {
	*a = "bye";
}

void setmessageref(const char*& a) {
	a = "ref!";
}

int main() {
	const char* msg = "hello";
	const char** pp = &msg; // 
	//const char*& pref = msg;
	setmessage(&msg); //  �׳� �����ͷδ� �ٲ��� ����, ���� �����ͷ� �Ѱ��ֱ�
	setmessageref(msg);
	cout << msg << endl;
}