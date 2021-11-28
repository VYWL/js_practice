#include <iostream>
#include <string>
using namespace std;

int main() {
	string str; cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		cout << str[i] << "__";
	}
	cout << str[str.size() - 1];
	return 0;
}