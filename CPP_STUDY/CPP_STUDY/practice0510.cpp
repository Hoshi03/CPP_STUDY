#include <iostream>
using namespace std;

//int swap(int *a, int *b) { // 포인터 방식
//	int c = *a;
//	*a = *b;
//	*b = c;
//	return 0;
//}
//
//void swap(int& a, int& b) { //참조 방식
//	int c = a;
//	a = b;
//	b = c;
//}

void sort(int numbers[], int count) { // 정렬 연습
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++) {
			if (numbers[i] > numbers[j]) {
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}


int main() {
	//int a = 1;
	//int b = 2;
	//cout << "a and b" << a << " " << b << endl;
	//swap(a, b);
	//cout << "a and b after swap" << a << " " << b;
	int numbers[6] = { 1,10,2,20,3,30 };
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
		cout << numbers[i] << " ";
	}
	sort(numbers, sizeof(numbers)/sizeof(int));
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
		cout  << numbers[i] << " ";
	}
}