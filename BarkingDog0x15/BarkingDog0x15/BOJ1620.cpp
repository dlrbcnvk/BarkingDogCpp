#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n, m;
string name;
unordered_map<string, int> s2i;
string i2s[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		s2i[name] = i;
		i2s[i] = name;
	}

	for (int i = 0; i < m; i++) {
		string query;
		cin >> query;
		if (isdigit(query[0])) {
			cout << i2s[stoi(query)] << "\n";
		}
		else {
			cout << s2i[query] << "\n";
		}
	}

	
}