#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int height[9] = { 0, };
int persons = 0;
vector<int> ans;

void find(int sum, vector<int> found, int toPick) {

	if (persons == 7 && sum == 100) {
		for (int i = 0; i < found.size(); i++)
			ans.push_back(found[i]);
		return;
	}

	if (toPick > 9)
		return;


	persons++;

	int smallest = (found.empty()) ? 0 : found.back() + 1;
	for (int i = smallest; i < 9; i++) {
		sum = sum + height[i];
		found.push_back(i);
		find(sum, found, toPick + 1);
		sum -= height[found.back()];
		found.pop_back();
		persons--;
	}
}


int main() {
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	sort(height, height + 9);
	vector<int> found;
	find(0, found, 0);
	for (int i = 0; i < ans.size(); i++) {
		cout << height[ans[i]] << endl;
	}

}