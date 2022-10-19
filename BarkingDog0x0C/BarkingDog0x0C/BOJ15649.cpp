#include <iostream>
using namespace std;

// one-based index
// for n numbers
bool selected[9] = { false, false, false, false, false, false, false, false, false };
// for m selecting
int sequence[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void go(int index, int n, int m) {

	if (index == m + 1) {
		// solution
		for (int i = 1; i <= m; i++) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!selected[i]) {
			selected[i] = true;
			sequence[index] = i;
			go(index + 1, n, m);
			selected[i] = false;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(1, n, m);
}