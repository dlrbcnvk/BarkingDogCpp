#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[1000][1000];
int dist[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	queue<pair<int, int>> Q;

	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i, j });
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = -1;
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (board[nx][ny] == -1 || board[nx][ny] == 1 || dist[nx][ny] >= 0) {
				continue;
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1 && board[i][j] == 0) {
				max = -1;
				cout << max;
				exit(0);
			}
			if (dist[i][j] > 0) {
				if (dist[i][j] > max) {
					max = dist[i][j];
				}
			}
		}
	}
	
	cout << max;
}