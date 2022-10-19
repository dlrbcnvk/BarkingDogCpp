#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<int> deque;
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		string command, str;
		getline(cin, command);
		int num;
		
		if (command == "size") {
			cout << deque.size() << endl;
		}
		else if (command == "empty") {
			if (deque.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (command == "front") {
			if (deque.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << deque.front() << endl;
			}
		}
		else if (command == "back") {
			if (deque.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << deque.back() << endl;
			}
		}
		else if (command == "pop_front") {
			if (deque.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << deque.front() << endl;
				deque.pop_front();
			}
		}
		else if (command == "pop_back") {
			if (deque.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << deque.back() << endl;
				deque.pop_back();
			}
		}
		else if (command.substr(0, 10) == "push_front") {
			num = stoi(command.substr(11));
			deque.push_front(num);
		}
		else if (command.substr(0, 9) == "push_back") {
			num = stoi(command.substr(10));
			deque.push_back(num);
		}
	}
}