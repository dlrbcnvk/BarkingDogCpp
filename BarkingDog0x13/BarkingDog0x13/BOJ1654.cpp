#include <iostream>
using namespace std;
typedef long long ll;
int lines[1000000];
int n, k, ans = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lines[i];
	}

	int st = 1;
	ll en = 1;
	for (int i = 0; i < 31; i++)
		en *= 2;
	en -= 1;

	int cnt = 0;
	while (st < en) {
		cnt = 0;
		ll mid = (st + en + 1) / 2;
		for (int i = 0; i < k; i++) {
			cnt += lines[i] / mid;
		}
		
		if (cnt < n) {
			en = mid - 1;
		}
		else if (cnt >= n) {
			st = mid;
			ans = mid;
		}
	}
	cout << ans;
}