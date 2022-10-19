#include <iostream>
#include <queue>
using namespace std;

int d[1001][3];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	}

	for (int i = 2; i <= n; i++) {
		d[i][0] = min(d[i-1][1] + d[i][0], d[i-1][2] + d[i][0]);
		d[i][1] = min(d[i-1][0] + d[i][1], d[i-1][2] + d[i][1]);
		d[i][2] = min(d[i-1][0] + d[i][2], d[i-1][1] + d[i][2]);
	}

	int result = min(min(d[n][0], d[n][1]), d[n][2]);
	cout << result;
}


//#define X first
//#define Y second
//// bfs 메모리 초과
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> d[i][0] >> d[i][1] >> d[i][2];
//	}
//
//	// index, col, total_cost
//	queue<pair<pair<int, int>, int>> q;
//	q.push({ {1,0}, d[1][0] });
//	q.push({ {1,1}, d[1][1] });
//	q.push({ {1,2}, d[1][2] });
//
//	int index, col, total_cost;
//	while (!q.empty()) {
//		pair<pair<int, int>, int> cur = q.front();
//		q.pop();
//
//		index = cur.X.X;
//		col = cur.X.Y;
//		total_cost = cur.Y;
//
//		if (index == n) {
//			if (total_cost < min_cost) {
//				min_cost = total_cost;
//			}
//			continue;
//		}
//
//		if (total_cost > min_cost) {
//			continue;
//		}
//
//		if (col == 0) {
//			q.push({ {index + 1, 1}, total_cost + d[index + 1][1] });
//			q.push({ {index + 1, 2}, total_cost + d[index + 1][2] });
//		}
//		else if (col == 1) {
//			q.push({ {index + 1, 0}, total_cost + d[index + 1][0] });
//			q.push({ {index + 1, 2}, total_cost + d[index + 1][2] });
//		}
//		else if (col == 2) {
//			q.push({ {index + 1, 1}, total_cost + d[index + 1][1] });
//			q.push({ {index + 1, 0}, total_cost + d[index + 1][0] });
//		}
//	}
//	cout << min_cost;
//}