#include <iostream>
#include <string>
using namespace std;

int main() {
	int arr[10] = {0,0,0,0,0,0,0,0,0,0};
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		char temp = str[i];
		int index = (int)(temp - '0');
		arr[index]++;
	}
	int sum;
	if ((arr[6] + arr[9]) % 2 == 0) {
		sum = (arr[6] + arr[9]) / 2;
	}
	else {
		sum = (arr[6] + arr[9]) / 2 + 1;
	}
	arr[9] = sum;

	int max = arr[0];
	for (int i = 1; i < 10; i++) {
		if (i == 6)
			continue;

		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max;
}