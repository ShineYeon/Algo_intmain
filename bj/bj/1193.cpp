#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int upper = 1, lower = 0;
	int layer = 1;
	while (1) {
		if (upper >= x && x>lower)
			break;
		lower = upper;
		upper += layer + 1;
		layer++;
	}

	
	int l = x - lower;
	int u = upper - x + 1;

	if (layer % 2 == 1)
		cout << u << "/" << l << endl;
	else
		cout << l << "/" << u << endl;
}