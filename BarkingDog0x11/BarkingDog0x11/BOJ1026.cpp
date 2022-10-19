#include <iostream>
#include <algorithm>
using namespace std;

int a[50], b[50];
int n;
int s = 0;

bool cmp(int x, int y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n, cmp);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		s += a[i] * b[i];
	}
	cout << s;
}