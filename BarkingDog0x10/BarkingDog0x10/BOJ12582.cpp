#include <iostream>
using namespace std;

int d[1000001];
int s[1000001];
int n;

// dp
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n] << "\n";

	int target = n;
	cout << target << " ";
	while (target > 1) {
		if (d[target - 1] == d[target] - 1) {
			target--;
			cout << target << " ";
			continue;
		}
		if (target % 2 == 0) {
			if (d[target / 2] == d[target] - 1) {
				target /= 2;
				cout << target << " ";
				continue;
			}
		}
		if (target % 3 == 0) {
			if (d[target / 3] == d[target] - 1) {
				target /= 3;
				cout << target << " ";
				continue;
			}
		}
	}
}