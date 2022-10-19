#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> men(7, 0);
	vector<int> women(7, 0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int is_man;
		int grade;
		cin >> is_man >> grade;
		if (is_man == 1) {
			men[grade]++;
		}
		else {
			women[grade]++;
		}
	}

	int room_count = 0;
	for (int i = 1; i <= 6; i++) {
		int count, rest;
		count = men[i] / k;
		rest = men[i] % k;
		if (rest != 0) {
			count++;
		}
		room_count += count;

		count = women[i] / k;
		rest = women[i] % k;
		if (rest != 0) {
			count++;
		}
		room_count += count;
	}

	cout << room_count;
}