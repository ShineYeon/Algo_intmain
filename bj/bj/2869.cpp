#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double a, b, v;	//a:���� �ö󰡴³���, b:�㿡 �̲������� ����, v:���� ����
	cin >> a >> b >> v;

	int day = (v - b - 1) / (a - b) + 1;
	cout << day << endl;
}