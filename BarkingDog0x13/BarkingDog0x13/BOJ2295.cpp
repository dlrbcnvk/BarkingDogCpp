#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> uni;
vector<int> twosum;
int n, num, maximum = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		uni.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			twosum.push_back(uni[i] + uni[j]);
		}
	}
	sort(twosum.begin(), twosum.end());
	twosum.erase(unique(twosum.begin(), twosum.end()), twosum.end());

	for (int k = 0; k < n; k++) {
		for (int l = k; l < n; l++) {
			if (binary_search(twosum.begin(), twosum.end(), uni[l] - uni[k])) {
				if (maximum < uni[l])
					maximum = uni[l];
			}
		}
	}
	cout << maximum;
}