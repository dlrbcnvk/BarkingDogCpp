#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec(1000001, 0);
	vector<int> tempvec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vec[k]++;
		tempvec.push_back(k);
	}

	int x;
	cin >> x;
	int count = 0;

	for (int i = 0; i < tempvec.size(); i++) {
		int diff = x - tempvec[i];
		if (diff > 1000000) {
			continue;
		}
		if (diff < 0) {
			continue;
		}
		if (vec[diff] == 1) {
			count++;
		}
	}
	
	cout << count / 2;

	return 0;
}