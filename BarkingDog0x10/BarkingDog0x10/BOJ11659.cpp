#include <iostream>
using namespace std;

int d[100001];
int n, m;
int i, j;
int sum = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	d[0] = 0;
	for (int a = 1; a <= n; a++) {
		cin >> d[a];
		d[a] = d[a - 1] + d[a];
	}
	for (int a = 0; a < m; a++) {
		cin >> i >> j;
		cout << d[j] - d[i - 1] << "\n";
	}
}