#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int H, M, N;
		cin >> H >> M >> N;

		int height, wide;
		height = N%H;
		wide = N/H+1;

		if (height == 0)
			height = H;
		if ((N%H) == 0)
			wide -= 1;

		cout << height *100 +wide << endl;
	
	}
}