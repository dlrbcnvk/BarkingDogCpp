#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second
#define fire 1000001

string board[1000];
int dist[1000][1000];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	queue<pair<int, int>> Q, Fire;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;
			if (board[i][j] == 'F') {
				dist[i][j] = fire;
				Fire.push({ i,j });
			}
			else if (board[i][j] == 'J') {
				dist[i][j] = 0;
				Q.push({ i,j });
			}
		}
	}

	int time = 0;
	while (!Q.empty()) {
		time++;
		// 시간이 1 증가할 때마다 불 지르기
		int fire_size = Fire.size();
		for (int i = 0; i < fire_size; i++) {
			pair<int, int> curFire = Fire.front();
			Fire.pop();
			dist[curFire.X][curFire.Y] = fire;
			for (int dir = 0; dir < 4; dir++) {
				int nx = curFire.X + dx[dir];
				int ny = curFire.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (board[nx][ny] == '.' && dist[nx][ny] != fire) {
					dist[nx][ny] = fire;
					Fire.push({ nx, ny });
				}
			}
		}

		int Q_size = Q.size();
		for (int i = 0; i < Q_size; i++) {
			pair<int, int> cur = Q.front();
			Q.pop();

			// find the first solution
			if (cur.X == 0 || cur.X == n - 1 || cur.Y == 0 || cur.Y == m - 1) {
				cout << time;
				exit(0);
			}

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				if (board[nx][ny] == '#' || dist[nx][ny] >= 0) {
					continue;
				}
				Q.push({ nx, ny });
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}