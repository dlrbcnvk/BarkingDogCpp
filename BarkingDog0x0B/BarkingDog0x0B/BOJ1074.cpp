#include <iostream>
#include <cmath>
using namespace std;

int find_z(int n, int r, int c) {
	
	if (n == 1) {
		if (r == 0 && c == 0) {
			return 0;
		}
		else if (r == 0 && c == 1) {
			return 1;
		}
		else if (r == 1 && c == 0) {
			return 2;
		}
		else if (r == 1 && c == 1) {
			return 3;
		}
	}
	
	int whole = pow(2, n);
	int half = whole / 2;
	int quad_rectangle = whole * whole / 4;
	
	if (r / half == 0 && c / half == 0) {
		return find_z(n - 1, r, c);
	}
	else if (r / half == 0 && c / half == 1) {
		return find_z(n - 1, r, c - half) + quad_rectangle;
	}
	else if (r / half == 1 && c / half == 0) {
		return find_z(n - 1, r - half, c) + quad_rectangle * 2;
	}
	else if (r / half == 1 && c / half == 1) {
		return find_z(n - 1, r - half, c - half) + quad_rectangle * 3;
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;

	int result = find_z(n, r, c);
	cout << result;
}