#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

pair<int, int> jewel[300003]; // (가격, 무게)
multiset<int> bag;
int n, k;
int weight, price;
ll sum = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> jewel[i].second >> jewel[i].first;
	}
	sort(jewel, jewel + n);
	for (int i = 0; i < k; i++) {
		cin >> weight;
		bag.insert(weight);
	}

	for (int i = n - 1; i >= 0; i--) {
		auto target = bag.lower_bound(jewel[i].second);
		if (target == bag.end()) 
			continue;
		sum += jewel[i].first;
		bag.erase(target);
	}

	cout << sum;
}