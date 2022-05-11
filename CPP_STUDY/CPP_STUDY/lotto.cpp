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

//void sort(int numbers[], int count) { // 정렬 연습
//	for (int i = 0; i < count; i++) {
//		for (int j = i + 1; j < count; j++) {
//			if (numbers[i] > numbers[j]) {
//				int temp = numbers[i];
//				numbers[i] = numbers[j];
//				numbers[j] = temp;
//			}
//		}
//	}
//}

void lotto(int numbers[]) {
	srand((unsigned)time(0));
	int cnt = 0;
	while (cnt != 6)
	{
		int randvalue = 1 + (rand() % 6);
		bool isequal = false;
		for (int i = 0; i < cnt; i++) {
			if (numbers[i] == randvalue)
			{
				cout << "일치 ";
				break;
			}
		}
		if (isequal == false) {
			numbers[cnt] = randvalue;
			cnt++;
		}
	}
}


int main() {
	//int a = 1;
	//int b = 2;
	//cout << "a and b" << a << " " << b << endl;
	//swap(a, b);
	//cout << "a and b after swap" << a << " " << b;
	//int numbers[6] = { 1,10,2,20,3,30 };
	//for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
	//	cout << numbers[i] << " ";
	//}
	//sort(numbers, sizeof(numbers)/sizeof(int));
	//for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
	//	cout  << numbers[i] << " ";
	//}

	int numbers[6] = {};
	lotto(numbers);
	for (int i = 0; i < sizeof(numbers) / sizeof(int); i++) {
		cout << numbers[i] << " ";
	}
}