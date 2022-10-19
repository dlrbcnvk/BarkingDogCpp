#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m;
ll num;
ll arr[100000];

int binarySearch(ll a, int start, int end);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		//cout << binarySearch(num, 0, n - 1) << "\n";
		cout << binary_search(arr, arr + n, num) << "\n";
	}
}

int binarySearch(ll a, int start, int end) {
	if (start > n - 1 || end < 0) {
		return 0;
	}
	if (start > end) {
		return 0;
	}

	int mid = (start + end) / 2;
	if ( a == arr[mid]) {
		return 1;
	}
	if (start == end) {
		return 0;
	}
	else if (a < arr[mid]) {
		return binarySearch(a, start, mid - 1);
	}
	else if (a > arr[mid]) {
		return binarySearch(a, mid + 1, end);
	}
}