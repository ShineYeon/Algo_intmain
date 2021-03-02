#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int arr[3] = { 1, 2, 3 };
vector<int> v;

void combSum(int n, int idx) {

	if (n < 0)
		return;
	if (n == 0) {
		cnt++;
		return;
	}
	
	for (int i = 0; i < 3; i++) {
		n -= arr[i];
		v.push_back(arr[i]);
		combSum(n, i);
		v.pop_back();
		n = n + arr[i];
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cnt = 0;
		int n;
		cin >> n;
		combSum(n, 0);
		
		cout << cnt << endl;
	}
}