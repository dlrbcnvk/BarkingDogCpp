#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ropes[100000];
int max_weight = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ropes[i];
	sort(ropes, ropes + n);
	for (int i = 0; i < n; i++) {
		if (max_weight < ropes[i] * (n - i)) {
			max_weight = ropes[i] * (n - i);
		}
	}
	cout << max_weight;
}