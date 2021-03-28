#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";
	for (int i = 0; i < new_id.size(); i++) {
		if (isalpha(new_id[i]))
			tolower(new_id[i]);
	}
	for (int i = 0; i < new_id.size(); i++) {
		if (!isdigit(new_id[i])) {
			if (!(new_id[i] == '-' || new_id[i] == '_' || new_id[i] != '.')) {
				new_id.erase(new_id.begin() + i);
				i--;
			}
		}
	}
	
	if (new_id[0] == '.')
		new_id.erase(new_id.begin());
	if (new_id[new_id.size() - 1] == '.')
		new_id.erase(new_id.begin() + new_id.size() - 1);

	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] == '.') {
			if (new_id[i - 1] == '.') {
				new_id.erase(new_id.begin() + i);
			}
		}
	}
	if (new_id.empty())
		new_id.push_back('a');

	if (new_id.size() >= 16) {
		for (int i = 15; i < new_id.size(); i++) {
			new_id.erase(new_id.begin() + i);
		}
	}
	if (new_id[new_id.size() - 1] == '.')
		new_id.erase(new_id.begin() + new_id.size() - 1);
	
	if (new_id.size() <= 2) {
		int idsz = new_id.size() - 1;
		while (new_id.size() >= 3) {
			char a = new_id[idsz];
			new_id.append(1, a);
		}
	}

	for (int i = 0; i < new_id.size(); i++) {
		answer += new_id[i];
	}
	return answer;
}

