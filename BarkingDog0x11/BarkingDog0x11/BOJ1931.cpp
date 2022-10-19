#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n;
int now = 0;
int first, second;
int cnt = 0;
pair<int, int> arr[100000];

bool cmp(pair<int, int> a, pair<int, int> b);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> first >> second;
		arr[i] = { first, second };
	}
	sort(arr, arr + n, cmp);
	
	for (int i = 0; i < n; i++) {
		if (now > arr[i].X)
			continue;

		now = arr[i].Y;
		cnt++;
	}
	cout << cnt;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.Y < b.Y) {
		return true;
	}
	else if (a.Y == b.Y) {
		return a.X < b.X;
	}
	return false;
}