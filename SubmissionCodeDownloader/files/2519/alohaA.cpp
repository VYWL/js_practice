#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	for (int i = 0; i < s.length()-1; i++) {
		cout << s[i] << "__";
	}
	int k = s.length() - 1;
	cout << s[k];
	return 0;
}