#include <iostream>
#include <regex>
#include <vector>
using namespace std;
int main() {
    vector<string> phone_numbers = {"010-1234-5678", "010-123-4567",
                                              "011-1234-5567", "010-12345-6789",
                                              "123-4567-8901", "010-1234-567"};
    regex re("[01]{3}-(\\d{3,4})-\\d{4}");
    smatch match;  // ��Ī�� ����� string ���� ����
    for (const auto& number : phone_numbers) {
        if (regex_match(number, match, re)) {
            for (size_t i = 0; i < match.size(); i++) {
                cout << "Match : " << match[i].str() << endl;
            }
            cout << "-----------------------\n";
        }
    }
}