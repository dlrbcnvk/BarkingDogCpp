#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100000];
int minvalue = 2147000000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);

	int st = 0, en = 0;

	while (en < n || st < n - 1) {

		while (en < n &&  a[en] - a[st] < m) {
			en++;
		}
		if (en == n) {
			break;
		}
		if (a[en] - a[st] == m) {
			cout << a[en] - a[st];
			return 0;
		}
		if (a[en] - a[st] < minvalue) {
			minvalue = a[en] - a[st];
		}
		st++;
	}
	cout << minvalue;
}