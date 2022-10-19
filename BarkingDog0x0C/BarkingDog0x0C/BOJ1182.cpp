#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, result_count = 0;
vector<int> vec;

bool bound(int index, int total) {
	if (vec[index + 1] > 0) {
		if (total + vec[index + 1] > s) {
			return false;
		}
	}
}

void part_sum(int index, int total) {

	if (index == vec.size() - 1) {
		if (total == s) {
			// find a solution
			result_count++;
		}
		return;
	}
	part_sum(index + 1, total + vec[index + 1]);
	part_sum(index + 1, total);
}

int main() {
	int num;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	part_sum(-1, 0);

	if (s == 0) {
		result_count--;
	}
	cout << result_count;
}