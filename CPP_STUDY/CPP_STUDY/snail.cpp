#include<iostream>
#include<iomanip> // input/output 조작
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

bool cango(int y, int x) {//갈수 있는지 없는지 판별하는 함수, 범위가 벗어나거나 이미 숫자가 들어가 있는 경우
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
	int y = 0; //상하
	int x = 0; //좌우
	int num = 1;

	int dy[] = {0, 1, 0, -1};
	int dx[] = {1, 0, -1, 0};


	while (true)
	{
		board[y][x] = num;

		if (num == n * n)// n제곱까지 가면 종료
			break;
		int nextY = y + dy[dir]; // 56~74 switch 문 부분을 대체 가능
		int nextX = x + dx[dir];
		
		//switch (dir) //배열 두개로 대체 가능
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
			num++; // 다음 좌표에 들어갈 값
		}
		else { //방향 전환 우 -> 하, 하 -> 좌, 좌->상, 상->우 방향으로만 감


			dir = (dir + 1) % 4; // 방향 순서대로 열거형을 만들어 두고 나머지연산으로 0123 0123 반복되게 루프, 87~101 대체

			//switch (dir) // switch문으로 구현하면 반복이 많음
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