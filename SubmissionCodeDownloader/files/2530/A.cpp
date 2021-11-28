#include <algorithm>
#include <isotream>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (i == s.size() - 1) {
			cout << s[i];
			break;
		}
		cout << s[i] << "  ";
	}
	return 0;
}
