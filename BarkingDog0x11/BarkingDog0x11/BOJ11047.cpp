#include <iostream>
using namespace std;

int n, k;
int coins[11];
int cnt = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coins[i];
	
	int idx = n;
	while (k > 0) {
		while (coins[idx] > k) {
			idx--;
		}
		while (k >= coins[idx]) {
			k -= coins[idx];
			cnt++;
		}
	}

	cout << cnt;
}