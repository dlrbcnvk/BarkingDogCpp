#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> firstvec(26, 0);
	vector<int> secondvec(26, 0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {

		string first, second;
		cin >> first >> second;
		for (int i = 0; i < first.length(); i++) {
			int index = (int)(first[i] - 'a');
			firstvec[index]++;
		}
		for (int i = 0; i < second.length(); i++) {
			int index = (int)(second[i] - 'a');
			secondvec[index]++;
		}

		string result = "Possible";
		for (int i = 0; i < 26; i++) {
			if (firstvec[i] != secondvec[i]) {
				result = "Impossible";
			}
		}
		cout << result << endl;
		firstvec = vector<int>(26, 0);
		secondvec = vector<int>(26, 0);
	}

	
}