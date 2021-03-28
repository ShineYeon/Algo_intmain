#include <iostream>
#include <string>
using namespace std;

int main() {
	string k;
	cin >> k;

	int arr[26] = { 0, };
	for (int i = 0; i < k.size(); i++) {
		if (k[i] < 97)
			arr[k[i] - 65]++;
		else
			arr[k[i] - 97]++;
	}

	int max = 0;
	int maxIdx = 0;
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			maxIdx = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (maxIdx == i)
			continue;
		if (max == arr[i]) {
			cout << "?" << endl;
			return 0;
		}
	}

	cout << (char)(maxIdx + 65) << endl;
	return 0;
}