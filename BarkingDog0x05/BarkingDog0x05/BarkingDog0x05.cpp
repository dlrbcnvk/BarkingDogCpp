#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> S;
	S.push(10);
	S.push(20);
	S.push(30);
	cout << S.size() << endl;
	if (S.empty()) {
		cout << "S is empty" << endl;
	}
	else {
		cout << "S is not empty" << endl;
	}
	S.pop();
	cout << S.top() << endl;
	S.pop();
	if (S.empty()) {
		cout << "S is empty" << endl;
	}
	cout << S.top() << endl;
}