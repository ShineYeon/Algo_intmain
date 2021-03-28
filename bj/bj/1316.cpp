#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	int grp = 0;
	while (T--) {
		string s;
		cin >> s;
		bool isGrp = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s[i + 1]) {
				for (int j = i + 2; j < s.size(); j++) {
					if (s[i] == s[j])
						isGrp = false;
				}
			}
		}
		if (isGrp == true)
			grp++;
	}
	cout << grp << endl;
}