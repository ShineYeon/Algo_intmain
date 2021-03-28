#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		cnt++;
		if (s[i] == '-') {
			cnt--;
			continue;
		}
		else if (s[i] == '=') {
			if (s[i - 1] == 'z'&&s[i - 2] == 'd')
				cnt-=2;
			else {
				cnt--;
				continue;
			}
		}
		else if (s[i] == 'j') {
			if (s[i - 1] == 'l') {
				cnt--;
				continue;
			}
			else if (s[i - 1] == 'n') {
				cnt--;
				continue;
			}
		}
	}

	cout << cnt << endl;
}