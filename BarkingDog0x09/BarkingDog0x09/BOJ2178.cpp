#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second

string bound[100];
int dist[100][100];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int n, m;
	cin >> n >> m;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> bound[i];
		for (int j = 0; j < m; j++) {
			char unit = bound[i][j];
			int data = atoi(&unit);
			
			dist[i][j] = -1;
		}
	}
	dist[0][0] = 1;

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (dist[nx][ny] > 0 || bound[nx][ny] != '1') {
				continue;
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	cout << dist[n - 1][m - 1];
}