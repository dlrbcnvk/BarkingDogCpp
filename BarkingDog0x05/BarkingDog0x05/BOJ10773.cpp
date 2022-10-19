#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<int> stack;
	string str;
	cin >> str;
	int n;
	n = stoi(str);
	for (int i = 0; i < n; i++) {
		cin >> str;
		int temp;
		temp = stoi(str);
		if (temp == 0) {
			stack.pop();
			continue;
		}

		stack.push(temp);
	}

	
	int sum = 0;
	while (!stack.empty()) {
		sum += stack.top();
		stack.pop();
	}
	cout << sum << endl;
}