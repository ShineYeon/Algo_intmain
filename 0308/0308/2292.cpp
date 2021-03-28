#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 0;
	int ed = 1;
	while (1) {
		ed = ed + i * 6;
		if (n <= ed)
			break;
		else
			i++;
	}

	cout << i+1 << endl;
}