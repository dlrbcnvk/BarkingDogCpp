#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	string first, second;
	cin >> first >> second;

	vector<int> firstvec(26, 0), secondvec(26, 0);
	for (int i = 0; i < first.length(); i++) {
		int index = (int)(first[i] - 'a');
		firstvec[index]++;
	}
	for (int i = 0; i < second.length(); i++) {
		int index = (int)(second[i] - 'a');
		secondvec[index]++;
	}

	int erase_count = 0;
	for (int i = 0; i < 26; i++) {
		if (firstvec[i] > secondvec[i]) {
			erase_count += firstvec[i] - secondvec[i];
		}
		else if (firstvec[i] < secondvec[i]) {
			erase_count += secondvec[i] - firstvec[i];
		}
	}
	cout << erase_count;
}