#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double a, b, v;	//a:낮에 올라가는높이, b:밤에 미끄러지는 높이, v:나무 높이
	cin >> a >> b >> v;

	int day = (v - b - 1) / (a - b) + 1;
	cout << day << endl;
}