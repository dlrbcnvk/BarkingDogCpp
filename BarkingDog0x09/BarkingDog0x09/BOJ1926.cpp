#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[500][500];
int visited[500][500];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			board[i][j] = 0;
			visited[i][j] = false;
		}
	}
	
	int data;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> data;
			board[i][j] = data;

		}
	}

	queue<pair<int, int>> Q;
	int max_size = 0;
	int painting_count = 0;
	
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (board[i][j] == 1 && !visited[i][j]) {
				int size = 0;
				Q.push({ i,j });
				visited[i][j] = true;
				size++;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
							continue;
						}
						if (visited[nx][ny] || board[nx][ny] != 1) {
							continue;
						}
						visited[nx][ny] = true;
						Q.push({ nx, ny });
						size++;
					}
				}
				if (size > max_size) {
					max_size = size;
				}
				painting_count++;
			}
		}
	}

	cout << painting_count << endl;
	cout << max_size << endl;
	
	return 0;
}