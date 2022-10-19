#include <iostream>
#include <list>
#include <string>
using namespace std;

void moveLeft(list<char>& editor, list<char>::iterator& t) {
	if (t != editor.begin()) {
		t--;
	}
}

void moveRight(list<char>& editor, list<char>::iterator& t) {
	if (t != editor.end()) {
		t++;
	}
}

void removeItem(list<char>& editor, list<char>::iterator& t) {
	if (t != editor.begin()) {
		t--;
		t = editor.erase(t);
	}
}

void add(list<char>& editor, list<char>::iterator& t, char character) {
	editor.insert(t, character);
}

int main() {
	string str;
	cin >> str;
	int n;
	cin >> n;
	list<char> editor;
	for (int i = 0; i < str.length(); i++) {
		editor.push_back(str[i]);
	}
	// ������ t�� � ���ڸ� ����Ű�� Ŀ���� �� ���ʿ� ������ �ǹ���.
	list<char>::iterator t = editor.end();// ���� Ŀ���� �� ��(end)�� ����Ű�� ����
	
	string temp;
	getline(cin, temp);

	for (int i = 0; i < n; i++) {
		getline(cin, temp);
		if (temp[0] == 'L') {
			moveLeft(editor, t);
		}
		else if (temp[0] == 'D') {
			moveRight(editor, t);
		}
		else if (temp[0] == 'B') {
			removeItem(editor, t);
		}
		else if (temp[0] == 'P') {
			add(editor, t, temp[2]);
		}
	}
	
	

	for (auto i : editor)
		cout << i;


	return 0;
}