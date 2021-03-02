#include <iostream>
#include <vector>
using namespace std;

vector<int> sang;
vector<int> imsi;


void findSang(int n) {

	int sum;
	int part;

	for (int i = 1; i < n; i++) {
		sum = i;
		part = i;
		while (part) {
			sum += part % 10;
			part /= 10;
		}
		if (n == sum) {
			cout << i << endl;
			return;
		}
	}
	cout << "0" << endl;
	return;

}

int main() {
	int n;
	cin >> n;
	findSang(n);
}