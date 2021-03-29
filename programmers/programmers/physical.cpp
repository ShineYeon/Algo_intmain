#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	
	int students[31] = { 0, };
	for (int i = 1; i <= n; i++) {
		students[i] = 1;
	}

	for (int i = 0; i < lost.size(); i++) {
		int lostIdx = lost[i];
		students[lostIdx]--;
	}

	for (int i = 0; i < reserve.size(); i++) {
		int reserveIdx = reserve[i];
		students[reserveIdx]++;
	}

	for (int i = 1; i <= n; i++) {
		if (students[i] == 0) {
			if ((i-1)>=1) {
				if (students[i - 1] >= 2) {
					students[i - 1]--;
					students[i]++;
					continue;
				}
			}
			if ((i + 1) <= n) {
				if (students[i + 1] >= 2) {
					students[i + 1]--;
					students[i]++;
					continue;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (students[i] > 0)
			answer++;
	}


	return answer;
}

int main() {
	vector<int> lost;
	lost.push_back(3);
	//lost.push_back(4);

	vector<int> reserve;
	//reserve.push_back(1);
	reserve.push_back(1);
	//reserve.push_back(5);

	cout << solution(3, lost, reserve) << endl;


}