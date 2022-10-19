#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
	queue<int> Q;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string command, str;
		getline(cin, command);
		str = command.substr(0, 3);

		if (str == "pus") {
			int temp = stoi(command.substr(5));
			Q.push(temp);
		}
		else if (str == "pop") {
			if (Q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		else if (str == "siz") {
			cout << Q.size() << endl;
		}
		else if (str == "emp") {
			if (Q.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (str == "fro") {
			if (Q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << Q.front() << endl;
			}
		}
		else if (str == "bac") {
			if (Q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << Q.back() << endl;
			}
		}
	}
}