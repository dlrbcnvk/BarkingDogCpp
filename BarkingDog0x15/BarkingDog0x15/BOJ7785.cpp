#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string name, action;

bool cmp(string a, string b) {
	if (a < b) {
		return true;
	}
	else false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unordered_set<string> workers;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> action;
		if (action == "enter") {
			workers.insert(name);
		}
		else if (action == "leave") {
			workers.erase(name);
		}
	}
	int workers_size = workers.size();
	vector<string> nameList(workers.begin(), workers.end());
	sort(nameList.begin(), nameList.end(), greater<string>());

	for (auto e : nameList) {
		cout << e << "\n";
	}
}