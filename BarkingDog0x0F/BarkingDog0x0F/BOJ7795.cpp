#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m, total = 0;
int alist[20000], blist[20000];

void test(int x, int y);

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		test(n, m);
	}
}

void test(int x, int y) {
	for (int i = 0; i < x; i++) {
		cin >> alist[i];
	}
	sort(alist, alist + x);
	for (int i = 0; i < y; i++) {
		cin >> blist[i];
	}
	sort(blist, blist + y);

	int bidx = -1;

	for (int aidx = 0; aidx < n; aidx++) {

		while (bidx < y - 1 && alist[aidx] > blist[bidx + 1]) {
			bidx++;
		}

		total += bidx + 1;
	}
	cout << total<<"\n";
	total = 0;
}