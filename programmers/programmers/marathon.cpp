#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

string solution(vector <string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> um;
	for (string name : participant) {
		um[name]++;
	}
	for (string name : completion) {
		um[name]--;
	}
	for (auto pair : um) {
		if (pair.second > 0) {
			answer = pair.first;
			break;
		}
	}

	return answer;
}

int main() {
	string a1 = "leo";
	string a2 = "kiki";
	string a3 = "eden";
	vector<string> participant;
	participant.push_back(a1);
	participant.push_back(a2);
	participant.push_back(a3);

	string b1 = "eden";
	string b2 = "kiki";
	vector<string> completion;
	completion.push_back(b1);
	completion.push_back(b2);

	cout << solution(participant, completion) << endl;

}