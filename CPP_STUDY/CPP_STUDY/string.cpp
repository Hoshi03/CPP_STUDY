#include<iostream>
using namespace std;

int Strlen(const char* str) {
	int count = 0;
	while (str[count] != '\0') { //�� ���ö����� �ݺ�!
		count++;
	}
	//cout << "���� ����: " << count << endl;
	//int* a = &count;
	//return *a;
	return count;
}

void Strcpy(char* dest, char* src) {
	int cnt = 0;
	while (src[cnt] != '\0') { // while(src[cnt]) ��  while(src[cnt] != 0) �� ���� �ǹ�
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
}

char* Strcat(char* dest, char* src) { // strlen���� ��ü�ؼ� while�� �� ������ �ؿ� �κе� strlen���� ��ü�ϸ� �ξ� �����ϰ� �ۼ� ����
	int cnt_src = 0;
	while (src[cnt_src])
		cnt_src++; // src ����, strlen���� ��ü ����
	int cnt_dest = 0;
	while (dest[cnt_dest])
		cnt_dest++; // dest ����
	int cnt = cnt_dest + cnt_src; // src�� dest�� ��ģ ����
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

int Strcmp(char a[], char b[]) { // char a[] �� char *a�� ����
	int cnt = 0;
	while (a[cnt] != 0 || b[cnt] != 0) { // ���� �ϳ��� ������ �ʾ�����
		if (a[cnt] > b[cnt])
			return 1;
		else if (a[cnt] < b[cnt])
			return -1;
		cnt++;
	}
	return 0;
}

//void Reversestr(char* str) { // �Լ� ����� �� ����
//	int i = Strlen(str);
//	int cnt = 0;
//	char arr[100];
//	Strcpy(arr, str);
//	while (arr[cnt] != 0) {
//		str[cnt] = arr[i-1];// ���̰� 5�� a[5]�ϸ� ���� ���� �۵� �ȵ�
//		cnt++;
//		i--;
//	}
//	cout << str << endl;
//}

void Reversestr(char* str) { // ��������ó�� temp�� ���� ���� ���ݱ��� �����ϱ�
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
	//cout << "����� " << d << endl;

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