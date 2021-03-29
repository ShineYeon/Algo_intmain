#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	
	int cnt[3] = { 0, };
	
	// 1번 수포자
	for (int i = 0; i < answers.size(); i++) {
		if (i % 5 + 1 == answers[i])
			cnt[0]++;
	}

	// 2번 수포자
	for (int i = 0; i < answers.size(); i++) {
		
		if ((i % 8 == 1) && answers[i] == 1)
			cnt[1]++;
		else if ((i % 8 == 3) && answers[i] == 3)
			cnt[1]++;
		else if ((i % 8 == 5) && answers[i] == 4)
			cnt[1]++;
		else if ((i % 8 == 7) && answers[i] == 5)
			cnt[1]++;
		else if ((i % 2 == 0) && answers[i] == 2)
			cnt[1]++;

	}
	

	// 3번 수포자
	for (int i = 0; i < answers.size(); i++) {
		if ((i % 10 == 0 || i % 10 == 1) && answers[i] == 3)
			cnt[2]++;
		else if ((i % 10 == 2 || i % 10 == 3) && answers[i] == 1)
			cnt[2]++;
		else if ((i % 10 == 4 || i % 10 == 5) && answers[i] == 2)
			cnt[2]++;
		else if ((i % 10 == 6 || i % 10 == 7) && answers[i] == 4)
			cnt[2]++;
		else if ((i % 10 == 8 || i % 10 == 9) && answers[i] == 5)
			cnt[2]++;
	}

	
	int max = cnt[0];
	for (int i = 1; i < 3; i++) {
		if (max < cnt[i])
			max = cnt[i];
	}

	for (int i = 0; i < 3; i++) {
		if (max == cnt[i])
			answer.push_back(i + 1);
	}

	return answer;
}


int main() {
	vector<int> answer;
	answer.push_back(1);
	answer.push_back(3);
	answer.push_back(2);
	answer.push_back(4);
	answer.push_back(2);
	vector<int> ans =  solution(answer);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}