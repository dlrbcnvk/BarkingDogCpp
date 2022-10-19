#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;
int t, k;
char cmd;
int num;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	for (int a = 0; a < t; a++) {
	
;		ms.clear();

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> cmd >> num;
			if (cmd == 'I') {
				ms.insert(num);
			}
			else if (cmd == 'D' && num == -1) {
				if (!ms.empty()) {
					ms.erase(ms.find(*ms.begin()));
				}
			}
			else if (cmd == 'D' && num == 1) {
				if (!ms.empty()) {
					ms.erase(prev(ms.end()));
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
		}
	}
}