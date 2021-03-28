#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	stack<int> st;
	queue<int> q;

	

	return answer;
}

int main() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2 = solution(v1);
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;
}