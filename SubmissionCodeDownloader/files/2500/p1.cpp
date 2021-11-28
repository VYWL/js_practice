#include <iostream>

using namespace std;

int main(void) {
	string S;
	cin >> S;
	
	for(int i = 0; i < S.length() - 1; ++i) {
		cout << S[i] << "__";
	}
	
	cout << S[S.length() - 1] << endl;
	return 0;
}
