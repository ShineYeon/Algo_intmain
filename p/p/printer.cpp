#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	//max값 찾기
	int maxNum = 0, maxIdx = 0;
	for (int i = 0; i < priorities.size(); i++) {
		if (maxNum < priorities[i]) {
			maxNum = priorities[i];
			maxIdx = i;
		}
	}

	while (1) {
		//max 찾았을 때
		priorities[maxIdx] = 0;
		answer++;
		maxNum = 0;

		//찾은게 location일 때
		if (maxIdx == location) {
			break;
		}

		//max 찾는 과정
		for (int i = maxIdx + 1; i < priorities.size(); i++) {
			if (maxNum < priorities[i]) {
				maxNum = priorities[i];
				maxIdx = i;
			}
		}
		for (int i = 0; i < maxIdx; i++) {
			if (maxNum < priorities[i]) {
				maxNum = priorities[i];
				maxIdx = i;
			}
		}

	}

	return answer;
}

int main() {
	vector<int> priorities;
	int location = 0;
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(9);
	priorities.push_back(1);
	priorities.push_back(1);
	priorities.push_back(1);

	cout << solution(priorities, location);
}