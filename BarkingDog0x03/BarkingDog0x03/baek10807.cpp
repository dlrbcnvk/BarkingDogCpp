#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(201, 0);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec[temp + 100]++;
	}
	int query;
	cin >> query;
	cout << vec[query + 100];
	
	return 0;
}