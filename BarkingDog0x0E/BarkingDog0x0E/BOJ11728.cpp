#include <iostream>
using namespace std;

int n, m;
int a[1000005], b[1000005], c[2000005];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int idx1 = 0, idx2 = 0, index = 0;
	while (idx1 < n && idx2 < m) {
		if (a[idx1] < b[idx2]) {
			c[index] = a[idx1++];
			index++;
		}
		else {
			c[index] = b[idx2++];
			index++;
		}
	}
	while (idx1 < n) {
		c[index] = a[idx1++];
		index++;
	}
	while (idx2 < m) {
		c[index] = b[idx2++];
		index++;
	}

	for (int i = 0; i < n + m; i++) {
		cout << c[i] << " ";
	}

	return 0;
}