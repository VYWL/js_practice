#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == s.size() - 1) {
			cout << s[i];
			break;
		}
		cout << s[i] << "__";
	}
	return 0;
}
