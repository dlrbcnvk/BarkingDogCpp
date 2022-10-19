#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n;
ll arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int max_count = 1;
	int freq_count = 1;
	int max_freq = 0;

	if (n == 1) {
		cout << arr[max_freq];
		return 0;
	}

	for (int i = 1; i < n; i++) {
		if (arr[i - 1] == arr[i]) {
			freq_count++;
		}
		else {
			if (freq_count > max_count) {
				max_count = freq_count;
				max_freq = i - 1;
			}
			freq_count = 1;
		}
	}

	if (freq_count > max_count) {
		max_count = freq_count;
		max_freq = n - 1;
	}

	cout << arr[max_freq];
	return 0;
}