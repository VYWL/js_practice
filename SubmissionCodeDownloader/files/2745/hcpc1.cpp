#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 9901;

int n, m, k;

int f(int n, int m, int d0) {
	if (n * m <= 1) return 0;

	int next = n * m - 1, sq = sqrt(next);
	for (int i = 1; i <= sq; ++i) {
		if (next % i != 0) continue;
		if (abs(abs(next / i - i) - d0) > k) continue;
		return f(next / i, i, d0) + 1;
	}

	return 0;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	cout << f(n, m, abs(n - m)) << '\n';


	return 0;
}