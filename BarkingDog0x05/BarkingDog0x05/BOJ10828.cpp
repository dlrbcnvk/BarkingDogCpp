#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {

	stack<int> stack;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		string str;
		getline(cin, str);
		if (str.substr(0, 3) == "pus") {
			str = str.substr(5, str.length());
			int temp = 0;
			int multiplier = 1;
			int length = str.length();
			for (int i = 0; i < length; i++) {
				int last = atoi(&str[length - (i + 1)]);
				temp += multiplier * last;
				str = str.substr(0, str.length() - 1);
				multiplier *= 10;
			}
			stack.push(temp);
		}
		else if (str.substr(0, 3) == "pop") {
			if (stack.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (str.substr(0, 3) == "siz") {
			cout << stack.size() << endl;
		}
		else if (str.substr(0, 3) == "emp") {
			if (stack.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (str.substr(0, 3) == "top") {
			if (stack.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << stack.top() << endl;
			}
		}
	}

	return 0;
}