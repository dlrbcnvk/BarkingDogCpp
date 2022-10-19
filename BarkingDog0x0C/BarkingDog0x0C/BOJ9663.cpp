#include <iostream>
#include <vector>
using namespace std;

#define X first;
#define Y second;

int n;
vector<pair<int, int>> vec;
int result_count = 0;

bool bound(int row, int col) {
	
	int x, y;
	for (auto spot : vec) {
		x = spot.X;
		y = spot.Y;
		if (x == row || y == col) {
			return false;
		}
		if (row - col == x - y || row + col == x + y) {
			return false;
		}
	}
	return true;
}

void queen(int row) {

	if (vec.size() == n) {
		result_count++;
	}

	for (int col = 0; col < n; col++) {
		if (bound(row, col)) {
			vec.push_back({ row, col });
			queen(row + 1);
			vec.pop_back();
		}
	}
}

int main() {
	cin >> n;

	queen(0);

	cout << result_count;
}