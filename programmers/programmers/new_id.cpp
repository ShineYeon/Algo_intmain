#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	string new_id2 = "";
	for (char& c : new_id)
		c = tolower(c);
	for (int i = 0; i < new_id.size(); i++) {
		if (!isdigit(new_id[i])) {
			if (!isalpha(new_id[i])) {
				if (!(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')) {
					continue;
				}
			}
		}
		new_id2.push_back(new_id[i]);
	}
	
	int idx = 0;
	while(1){
		if (idx == new_id2.size() - 1)
			break;
		if (new_id2[idx] == '.') {
			if (new_id2[idx + 1] == '.') {
				new_id2.erase(new_id2.begin() + idx + 1);
				continue;
			}
		}
		idx++;
	}

	if (!new_id2.empty()) {
		while (new_id2[0] == '.')
			new_id2.erase(new_id2.begin());
	}
	if (!new_id2.empty()) {
		while (new_id2[new_id2.size() - 1] == '.')
			new_id2.erase(new_id2.begin() + new_id2.size() - 1);
	}

	if (new_id2.empty())
		new_id2 = "a";

	string new_id3 = "";
	if (new_id2.length() >= 16) {
		for (int i = 0; i < 15; i++) {
			new_id3.push_back(new_id2[i]);
		}
	}
	else {
		for (int i = 0; i < new_id2.size(); i++) {
			new_id3.push_back(new_id2[i]);
		}
	}
	
	if (new_id3[new_id3.size() - 1] == '.')
		new_id3.erase(new_id3.begin() + new_id3.size() - 1);
	
	if (new_id3.size() <= 2) {
		int idsz = new_id3.size() - 1;
		char a = new_id3[idsz];
		while (new_id3.size() < 3) {
			new_id3.push_back(a);
		}
	}

	for (int i = 0; i < new_id3.size(); i++) {
		answer.push_back(new_id3[i]);
	}
	return answer;
}

int main() {
	string k = "...!@BaT#*..y.abcdefghijklm";
	cout << solution(k) << endl;
	string k2 = "z-+.^.";
	cout << solution(k2) << endl;
	string k3 = "=.=";
	cout << solution(k3) << endl;
	string k4 = "123_.def";
	cout << solution(k4) << endl;
	string k5 = "abcdefghijklmn.p";
	cout << solution(k5) << endl;
}