#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 1000005, INF = 1000000001, MOD = 9901;

int n;
vi e, c;
bool chk[1001];

ll f(int cnt, ll s) {
	if (cnt >= n) return 0;

	ll ret = 0;
	for (int i = 0; i < n; ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		ret = max(ret, f(cnt + 1, s + c[i]) + max(0LL, e[i] - s));
		chk[i] = false;
	}

	return ret;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	e.resize(n); c.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> e[i];
	}

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	cout << f(0, 0) << '\n';


	return 0;
}