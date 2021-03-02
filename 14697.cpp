#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int insil[3];
int MAX;

void allIn(int total, int sta) {
	if (total == MAX) {
		cout << 1;
		exit(0);
	}
	else if (total > MAX) {
		return;
	}
	else {
		for (int i = sta; i < 3; i++) {
			allIn(total + insil[i], i);
		}
	}
}

int main() {
	int data;
	for (int & i : insil) {
		cin >> data;
		i = data;
	}
	cin >> data;
	MAX = data;
	allIn(0, 0);
	cout << 0;
}