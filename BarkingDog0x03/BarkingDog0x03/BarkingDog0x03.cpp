#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec1(26, 0);
	string word;
	cin >> word;
	
	int len = word.length();
	for (int i = 0; i < len; i++) {
		int alphabet_index = word[i] - 'a';
		vec1[alphabet_index]++;
	}

	for (int e : vec1) {
		cout << e << " ";
	}
}