#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i != s.size() - 1)
			cout << s[i] << "__";
		else
			cout << s[i];
	}
	 
	return 0;
}
