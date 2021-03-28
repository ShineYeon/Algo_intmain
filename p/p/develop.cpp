#include <string>
#include <stack>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int idx = 0, cnt = 0;
	bool flag = false;
	while (idx < progresses.size()) {
		for (int i = idx; i < progresses.size(); i++) {
			progresses[i] += speeds[i];
		}
		while (progresses[idx] >= 100) {
			idx++;
			cnt++;
			flag = true;
			if (idx == progresses.size())
				break;
		}
		if (flag == true) {
			answer.push_back(cnt);
			cnt = 0;
			flag = false;
		}
	}
	return answer;
}

int main() {
	vector<int> progresses;
	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);
	vector<int> speeds;
	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);
	
	vector<int> sol = solution(progresses, speeds);
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
}