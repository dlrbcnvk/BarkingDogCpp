#include <iostream>
using namespace std;

int d[1001][1001];
int n, k;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	d[1][0] = 1; d[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
			}
		}
	}
	cout << d[n][k];
}