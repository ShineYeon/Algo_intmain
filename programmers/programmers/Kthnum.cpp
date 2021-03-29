#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	int i = commands.size();
	for(int k=0;k<i;k++) {
		int start = commands[k][0] - 1;
		int back = commands[k][1] - 1;
		int target = commands[k][2] - 1;
		vector<int> tmp;
		for (int j = start; j <= back; j++) {
			tmp.push_back(array[j]);
		}
		sort(tmp.begin(), tmp.end());

		answer.push_back(tmp[target]);
	}
	
	return answer;
}

int main() {
	vector<int> array;
	array.push_back(1);
	array.push_back(5);
	array.push_back(2);
	array.push_back(6);
	array.push_back(3);
	array.push_back(7);
	array.push_back(4);

	vector<int> a1;
	a1.push_back(2);
	a1.push_back(5);
	a1.push_back(3);
	vector<int> a2;
	a2.push_back(4);
	a2.push_back(4);
	a2.push_back(1);
	vector<int> a3;
	a3.push_back(1);
	a3.push_back(7);
	a3.push_back(3);
	vector<vector<int>>commands;
	commands.push_back(a1);
	commands.push_back(a2);
	commands.push_back(a3);

	vector<int> retu = solution(array, commands);
	for (int i = 0; i < retu.size(); i++) {
		cout << retu[i] << " ";
	}
	cout << endl;
}