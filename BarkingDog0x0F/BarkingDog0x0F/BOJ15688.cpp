#include <iostream>
using namespace std;

int n, num;
int cnt[2000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 2000005; i++) {
		cnt[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cnt[num + 1000000]++;
	}

	for (int i = 0; i < 2000005; i++) {
		if (cnt[i] != 0) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << i - 1000000 << "\n";
			}
		}
	}
}