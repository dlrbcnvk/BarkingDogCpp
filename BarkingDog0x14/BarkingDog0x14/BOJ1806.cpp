#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[100005];
int minvalue = 2100000000;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int st = 0, en = 0;
	int sum = 0;
	while (st < n) {

		while (en < n && sum < s) {
			sum += arr[en];
			en++;
		}
		if (sum >= s && en - st < minvalue) {
			minvalue = en - st;
		}
		sum -= arr[st];
		st++;
	}
	if (minvalue == 2100000000) {
		cout << 0;
	}
	else {
		cout << minvalue;
	}
}

