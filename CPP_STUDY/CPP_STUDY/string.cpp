#include<iostream>
using namespace std;

int Strlen(const char* str) {
	int count = 0;
	while (str[count] != '\0') { //널 나올때까지 반복!
		count++;
	}
	//cout << "문자 갯수: " << count << endl;
	//int* a = &count;
	//return *a;
	return count;
}

void Strcpy(char* dest, char* src) {
	int cnt = 0;
	while (src[cnt] != '\0') { // while(src[cnt]) 나  while(src[cnt] != 0) 과 같은 의미
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
}

char* Strcat(char* dest, char* src) { // strlen으로 대체해서 while문 다 날리고 밑에 부분도 strlen으로 대체하면 훨씬 간결하게 작성 가능
	int cnt_src = 0;
	while (src[cnt_src])
		cnt_src++; // src 갯수, strlen으로 대체 가능
	int cnt_dest = 0;
	while (dest[cnt_dest])
		cnt_dest++; // dest 갯수
	int cnt = cnt_dest + cnt_src; // src와 dest를 합친 길이
	int a = cnt - cnt_src;
	char result[100];
	Strcpy(result, src);
	int count = 0;
	while (dest[count] != 0 && a < cnt) {
		result[a] = dest[count];
		count++;
		a++;
	}
	result[a] = 0;
	/*cout << result << endl;*/
	return result;

}

int Strcmp(char a[], char b[]) { // char a[] 나 char *a나 같음
	int cnt = 0;
	while (a[cnt] != 0 || b[cnt] != 0) { // 둘중 하나라도 끝나지 않았으면
		if (a[cnt] > b[cnt])
			return 1;
		else if (a[cnt] < b[cnt])
			return -1;
		cnt++;
	}
	return 0;
}

//void Reversestr(char* str) { // 함수 만든거 쓴 버전
//	int i = Strlen(str);
//	int cnt = 0;
//	char arr[100];
//	Strcpy(arr, str);
//	while (arr[cnt] != 0) {
//		str[cnt] = arr[i-1];// 길이가 5면 a[5]하면 널이 떠서 작동 안됨
//		cnt++;
//		i--;
//	}
//	cout << str << endl;
//}

void Reversestr(char* str) { // 버블정렬처럼 temp를 만들어서 길이 절반까지 정렬하기
	int len = Strlen(str);
	for (int i = 0; i < len / 2; i++) {
		int temp = str[i];
		str[i] = str[len-1-i];
		str[len - 1 - i] = temp;
	}
}

int main() {
	//char a[] = "\0";
	//Strlen(a);
	//int b =strlen(a);
	//cout << b << endl;
	//const int size = 100;
	//char c[size] = "hellooo";
	//char d[size];
	//Strcpy(d, c);
	//cout << "만든거 " << d << endl;

	//char e[] = "hello ";
	//char f[] = "world!";
	//Strcat(f, e);
	//cout << Strlen(c) << endl;
	//char a[] = "hello";
	//char b[] = "hi";
	//int val = Strcmp(a, b);
	//cout << val << endl;

	char a[] = "abcde";
	Reversestr(a);
	cout << a << endl;
	

	return 0;


}