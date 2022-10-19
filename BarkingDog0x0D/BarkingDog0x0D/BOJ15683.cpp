#include <iostream>
#include <vector>
using namespace std;
#define X first;
#define Y second;

int n, m, num, min_count = 0, count = 0;
vector<vector<int>> vec;

bool equal_pair(pair<int, int>& p1, pair<int, int>& p2);

void coloring_5(vector<vector<int>>& vec);

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		vec.push_back(vector<int>());
		for (int j = 0; j < m; j++) {
			cin >> num;
			vec[i].push_back(num);
			if (num >= 1 && num <= 5) {
				min_count++;
			}
		}
	}
	coloring_5(vec);

	
	

}

void coloring_5(vector<vector<int>>& vec) {
	// 5번 먼저 영역표시
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] == 5) {
				for (int k = i - 1; k >= 0; k--) {
					if (vec[k][j] == 6)
						break;
					if (vec[k][j] == 0) {
						vec[k][j] = 7;
						min_count++;
					}
				}
				for (int k = i + 1; k < n; k++) {
					if (vec[k][j] == 6)
						break;
					if (vec[k][j] == 0) {
						vec[k][j] = 7;
						min_count++;
					}
				}
				for (int k = j - 1; k >= 0; k--) {
					if (vec[i][k] == 6)
						break;
					if (vec[i][k] == 0) {
						vec[i][k] = 7;
						min_count++;
					}
				}
				for (int k = j + 1; k < m; k++) {
					if (vec[i][k] == 6)
						break;
					if (vec[i][k] == 0) {
						vec[i][k] = 7;
						min_count++;
					}
				}
			}
		}
	}
}

bool equal_pair(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first == p2.first && p1.second == p2.second) {
		return true;
	}
	return false;
}