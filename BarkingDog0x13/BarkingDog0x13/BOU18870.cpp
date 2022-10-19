#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int arr[1000001];
int n, num, set_size;

int bs_idx(int cur);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> q;
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
		arr[i] = num;
		q.push(num);
	}
	set_size = s.size();
	int i = 0;
	for (auto elem : s) {
		arr[i] = elem;
		i++;
	}

	int idx;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		cout << bs_idx(cur) << " ";
		
	}
}

int bs_idx(int cur) {
	int st = 0;
	int en = set_size - 1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (cur == arr[mid]) {
			return mid;
		}
		else if (cur < arr[mid]) en = mid - 1;
		else if (cur > arr[mid]) st = mid + 1;
	}
}