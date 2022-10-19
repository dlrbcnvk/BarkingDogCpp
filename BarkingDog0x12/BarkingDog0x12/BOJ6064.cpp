// ¹ÌÇØ°á

#include <iostream>
using namespace std;

int t, m, n, x, y;
int mod;

int kaing(int a, int b, int p, int q);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n >> x >> y;
		if (m >= n) {
			cout << kaing(m, n, x, y) << "\n";
		}
		else {
			cout << kaing(n, m, y, x) << "\n";
		}
	}
}

int kaing(int a, int b, int p, int q) { 
	// a > b
	// a -> p, b -> q
	int mod = a % b;
	if (mod == 0) {
		if (q % b == p % b) {
			return p;
		}
		return -1;
	}
	if (p <= a) {
		if (q % b == p % b) {
			return p;
		}
		return -1;
	}
	if (p == a * b) {
		if (q == b) {
			return a * b;
		}
		return -1;
	}
	int start_q = q - p;
	while (start_q <= 0) {
		start_q += b;
	}
	int group_start = start_q;
	int ingroup_cnt = 0;
	while (group_start > mod) {
		group_start -= mod;
		ingroup_cnt++;
	}
	int group_size = (b / mod) * a;
	int result = a - 1;
	int multiple = mod - group_start;

}