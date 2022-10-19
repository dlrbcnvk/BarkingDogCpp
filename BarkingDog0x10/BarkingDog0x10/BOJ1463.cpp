#include <iostream>
using namespace std;

int d[1000001];
int n;

// dp
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n];
}


//// using BFS
//int main() {
//	cin >> n;
//	queue<pair<int, int>> q;
//	q.push({ n, 0 });
//
//	while (!q.empty()) {
//		int num = q.front().X;
//		int count = q.front().Y;
//		q.pop();
//
//		if (count > minvalue) {
//			continue;
//		}
//
//		if (num == 1) {
//			if (count < minvalue) {
//				minvalue = count;
//			}
//		}
//
//		if (num % 3 == 0) {
//			q.push({ num / 3, count + 1 });
//		}
//		if (num % 2 == 0) {
//			q.push({ num / 2, count + 1 });
//		}
//		q.push({ num - 1, count + 1 });
//	}
//
//	cout << minvalue;
//}