#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i != s.length() - 1) {
			cout << s[i] << "__";
		}
		else cout << s[i];
	}
}