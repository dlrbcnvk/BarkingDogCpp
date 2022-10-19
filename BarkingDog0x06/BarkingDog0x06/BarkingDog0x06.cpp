#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> Q;
	Q.push(10);
	Q.push(20);
	Q.push(30);
	cout << Q.size() << endl;
	if (Q.empty())
		cout << "Q is empty" << endl;
	Q.pop();
	cout << Q.front() << endl;
	cout << Q.back() << endl;
	Q.push(40);
	Q.pop();
	cout << Q.front() << endl;
}