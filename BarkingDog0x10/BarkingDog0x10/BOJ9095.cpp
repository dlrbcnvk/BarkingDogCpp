#include <iostream>
using namespace std;

int t, n;
int d[11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 10; i++) {
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << d[n] << "\n";
	}
}