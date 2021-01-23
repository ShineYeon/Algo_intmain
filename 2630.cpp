#include <iostream>
using namespace std;

int arr[128][128];
int white, blue;

int colorPaper(int x, int y, int n) {
	//기저사례: 나눈n이 1이 되었을 경우
	if (n == 1) {
		return arr[x][y];
	}

	int upperLeft = colorPaper(x, y, n / 2);
	int lowerLeft = colorPaper(x + n / 2, y, n / 2);
	int upperRight = colorPaper(x, y + n / 2, n / 2);
	int lowerRight = colorPaper(x + n / 2, y + n / 2, n / 2);
	
	if (upperLeft == lowerLeft&&upperLeft == upperRight&&upperLeft == lowerRight) {
		return upperLeft;
	}

	else {
		if (upperLeft == 0)
			white++;
		else if (upperLeft == 1)
			blue++;
		if (lowerLeft == 0)
			white++;
		else if (lowerLeft == 1)
			blue++;
		if (upperRight == 0)
			white++;
		else if (upperRight == 1)
			blue++;
		if (lowerRight == 0)
			white++;
		else if (lowerRight == 1)
			blue++;
		return -1;
	}

}

int main() {
	int N;
	cin >> N;	// 전체 종이의 한변의 길이
				// N은 2, 4, 8, 16, 32, 64, 128 중 하나
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	colorPaper(0, 0, N);
	cout << white << endl << blue << endl;
}