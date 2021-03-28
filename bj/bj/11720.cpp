#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	string k;
	cin >> k;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += k[i] - '0';
	}
	cout << sum << endl;
}