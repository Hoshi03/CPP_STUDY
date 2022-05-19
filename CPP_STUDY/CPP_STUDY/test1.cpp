#include <iostream>
using namespace std;
#include "test1.h"

void test1() {
	test2();
}

void test2() {
	cout << "hello world!" << endl;
}