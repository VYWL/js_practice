#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, ret; cin >> s;
	for (int i = 0; i < s.size() - 1; ++i) {
		ret += s[i];
		ret += "__";
	}

	ret += s[s.size() - 1];

	cout << ret << '\n';

	return 0;
}