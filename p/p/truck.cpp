#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	
	queue <int> bridge;

	int idx = 0;
	int totalWeight = 0;
	while (1) {

		// 맨 마지막 트럭에 도달했을때
		if (idx == truck_weights.size()) {
			answer += bridge_length;
			break;
		}

		//그 이전
		answer++;

		if (bridge.size() == bridge_length) {
			totalWeight -= bridge.front();
			bridge.pop();
		}

		if (totalWeight + truck_weights[idx] <= weight) {
			totalWeight += truck_weights[idx];
			bridge.push(truck_weights[idx]);
			idx++;
		}

		else {
			bridge.push(0);
		}
		
	}

	return answer;

}

int main() {
	vector<int> v1;
	v1.push_back(7);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	cout << solution(2, 10, v1) <<"\n";

	vector<int> v2;
	v2.push_back(10);
	cout << solution(100, 100, v2) << "\n";
}