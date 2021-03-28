#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	int a = 0, b = 0;
	for (int i = 0; i < 3; i++) {
		a += (A[i]-'0') * pow(10, i);
		b += (B[i]-'0') * pow(10, i);
	}

	if (a < b)
		cout << b << endl;
	else if (a > b)
		cout << a << endl;

}