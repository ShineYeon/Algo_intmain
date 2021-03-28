#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	//max�� ã��
	int maxNum = 0, maxIdx = 0;
	for (int i = 0; i < priorities.size(); i++) {
		if (maxNum < priorities[i]) {
			maxNum = priorities[i];
			maxIdx = i;
		}
	}

	while (1) {
		//max ã���� ��
		priorities[maxIdx] = 0;
		answer++;
		maxNum = 0;

		//ã���� location�� ��
		if (maxIdx == location) {
			break;
		}

		//max ã�� ����
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