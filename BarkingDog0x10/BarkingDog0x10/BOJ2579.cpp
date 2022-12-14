#include <iostream>
using namespace std;

// d[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지
// 올라섰을 때 점수 합의 최댓값, 단 i번째 계단은 반드시 밟아야 함
int d[301][301];
int points[301];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = 0;
		}
		cin >> points[i];
	}
	d[1][1] = points[1];
	d[1][2] = 0;
	d[2][1] = points[2];
	d[2][2] = points[1] + points[2];
	for (int i = 3; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + points[i];
		d[i][2] = d[i - 1][1] + points[i];
	}
	cout << max(d[n][1], d[n][2]);
}