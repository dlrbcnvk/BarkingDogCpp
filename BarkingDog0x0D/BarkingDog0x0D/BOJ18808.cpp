#include <vector>
#include <iostream>
using namespace std;

int n, m, k;
vector<vector<vector<int>>> stickers;
vector<vector<int>> board;

bool search(vector<vector<int>>& sticker, int rotate_count);
vector<vector<int>> rotate(vector<vector<int>>& sticker);
bool fitting(int x, int y, vector<vector<int>>& sticker);

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			temp.push_back(0);
		}
		board.push_back(temp);
	}
	
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		vector<vector<int>> sticker;
		for (int a = 0; a < r; a++) {
			vector<int> row;
			int temp;
			for (int b = 0; b < c; b++) {
				cin >> temp;
				row.push_back(temp);
			}
			sticker.push_back(row);
		}
		stickers.push_back(sticker);
	}

	for (auto sticker : stickers) {
		search(sticker, 0);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1)
				count++;
		}
	}
	cout << count;
	return 0;
}

bool search(vector<vector<int>>& sticker, int rotate_count) {
	bool result = false;
	int a = sticker.size();
	int b = sticker[0].size();

	if (a > n || b > m) {
		if (rotate_count == 3) { // 270도 회전에서도 안 맞는 경우
			return false;
		}
		vector<vector<int>> rotated = rotate(sticker);
		result = search(rotated, rotate_count + 1);
	}
	
	if (result)
		return result;

	bool is_fitted = false;
	int fit_x, fit_y;
	for (int i = 0; i <= n - a; i++) {
		for (int j = 0; j <= m - b; j++) {
			if (is_fitted)
				break;

			is_fitted = fitting(i, j, sticker);
			fit_x = i;
			fit_y = j;
		}
	}

	if (is_fitted) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (board[fit_x + i][fit_y + j] == 0) {
					board[fit_x + i][fit_y + j] = sticker[i][j];
				}
			}
		}
		return true;
	}
	else {
		if (rotate_count == 3)
			return false;
		vector<vector<int>> rotated = rotate(sticker);
		return search(rotated, rotate_count + 1);
	}
}

bool fitting(int x, int y, vector<vector<int>>& sticker) {
	int a = sticker.size();
	int b = sticker[0].size();
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (board[x + i][y + j] == 1 && sticker[i][j] == 1)
				return false;
		}
	}
	return true;
}

vector<vector<int>> rotate(vector<vector<int>>& sticker) {
	int a = sticker.size();
	int b = sticker[0].size();
	vector<int> new_row(a, 0);
	vector<vector<int>> rotated_sticker(b, new_row);
	for (int x = 0; x < a; x++) {
		for (int y = 0; y < b; y++) {
			rotated_sticker[y][a - 1 - x] = sticker[x][y];
		}
	}
	return rotated_sticker;
}