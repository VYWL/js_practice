#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long //instead of int main, use signed main
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<int, int, int, int> tiiii;
//const int INF = 100000000;
const int INF = 4500000000000000000;
typedef pair<int, char> pic;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvp;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
//const int MOD = (1ll << 32);

vvi grid;
int solve(int x, int y, int n) {
	if (n == 1) return grid[x][y];
	vi s;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			s.push_back(solve(x + n / 2 * i, y + n / 2 * j, n / 2));
		}
	}
	sort(s.begin(), s.end());
	return s[1];
}

signed main() {
	IOS;

	int n; cin >> n;
	grid.resize(n, vi(n));
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
	cout << solve(0, 0, n);
}
