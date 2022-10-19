#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;

	int mul = A * B * C;
	vector<int> vec(10, 0);
	string str = to_string(mul);
	for (int i = 0; i < str.length(); i++) {
		int temp = (int)(str[i] - '0');
		vec[temp]++;
	}

	for (int e : vec) {
		cout << e << endl;
	}
}