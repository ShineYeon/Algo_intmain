#include <iostream>
#include <vector>
using namespace std;

int cards[101];
int cnt = 0;
vector<int> ans;

void combCard(int n, int m, int idx, int desti) {
	
	if (m > desti)
		return;

	if (cnt == 3 && m <= desti) {
		ans.push_back(m);
		return;
	}

	for (int i = idx; i < n; i++) {
		m += cards[i];
		cnt++;
		combCard(n, m, i + 1, desti);
		m -= cards[i];
		cnt--;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	combCard(n, 0, 0, m);

	int minDist = 1000000;
	int appro;
	for (int i = 0; i < ans.size(); i++) {
		int dist = ans[i] - m;
		if (dist < 0)
			dist = -(dist);
		if (dist < minDist) {
			minDist = dist;
			appro = ans[i];
		}
	}
	cout << appro << endl;
}