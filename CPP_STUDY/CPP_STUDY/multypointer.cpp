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
	setmessage(&msg); //  그냥 포인터로는 바뀌지 않음, 이중 포인터로 넘겨주기
	setmessageref(msg);
	cout << msg << endl;
}