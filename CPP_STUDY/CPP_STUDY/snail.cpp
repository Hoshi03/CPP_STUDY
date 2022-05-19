#include<iostream>
#include<iomanip> // input/output ����
using namespace std;


const int Max = 100;
int board[Max][Max] = {};
int n;

enum dir {
	Right = 0,
	Down = 1,
	Left = 2,
	Up = 3
};

void printboard() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
		cout << endl;
	}
}

bool cango(int y, int x) {//���� �ִ��� ������ �Ǻ��ϴ� �Լ�, ������ ����ų� �̹� ���ڰ� �� �ִ� ���
	if (y < 0 || y >= n)
		return false;
	if (x < 0 || x >= n)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void setboard() {
	int dir = 0;
	int y = 0; //����
	int x = 0; //�¿�
	int num = 1;

	int dy[] = {0, 1, 0, -1};
	int dx[] = {1, 0, -1, 0};


	while (true)
	{
		board[y][x] = num;

		if (num == n * n)// n�������� ���� ����
			break;
		int nextY = y + dy[dir]; // 56~74 switch �� �κ��� ��ü ����
		int nextX = x + dx[dir];
		
		//switch (dir) //�迭 �ΰ��� ��ü ����
		//{
		//case Right:
		//	nextY = y;
		//	nextX = x+1;
		//	break;
		//case Down:
		//	nextY = y+1;
		//	nextX = x;
		//	break;
		//case Left:
		//	nextY = y;
		//	nextX = x-1;
		//	break;
		//case Up:
		//	nextY = y-1;
		//	nextX = x;
		//	break;
		//}
		

		if (cango(nextY, nextX)) {
			y = nextY;
			x = nextX;
			num++; // ���� ��ǥ�� �� ��
		}
		else { //���� ��ȯ �� -> ��, �� -> ��, ��->��, ��->�� �������θ� ��


			dir = (dir + 1) % 4; // ���� ������� �������� ����� �ΰ� �������������� 0123 0123 �ݺ��ǰ� ����, 87~101 ��ü

			//switch (dir) // switch������ �����ϸ� �ݺ��� ����
			//{
			//case Right:
			//	dir = Down;
			//	break;
			//case Down:
			//	dir = Left;
			//	break;
			//case Left:
			//	dir = Up;
			//	break;
			//case Up:
			//	dir = Right;
			//	break;
			//}
		}


	}

	
}

int main() {

	cin >> n;
	setboard();
	printboard();

	return 0;
}