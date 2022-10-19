#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n, m, num;

int find_first(int a);
int find_last(int a);

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
		int first = find_first(num);
		int last = find_last(num);
		if (first != last) {
			cout << last - first << " ";
		}
		else if (first == last) {
			cout << 0 << " ";
		}
	}
}

int find_first(int a) {
	int st = 0;
	int en = n;
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid] >= a) en = mid;
		else st = mid + 1;
	}
	return st;
}

int find_last(int a) {
	int st = 0;
	int en = n;
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid] > a) en = mid;
		else st = mid + 1;
	}
	return st;
}