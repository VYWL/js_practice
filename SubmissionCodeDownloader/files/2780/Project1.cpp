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
#ifdef _MSC_VER == 1930 
#  define __builtin_popcount __popcnt
#endif
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
//const int MOD = (1ll << 32);

signed main() {
	IOS;
	
	int n, m; cin >> n >> m;
	vi er(n * 2); for (int i = 0; i < m; i++) {
		int k; cin >> k;
		k--;
		er[k] = 1;
	}
	for (int i = n; i < n * 2; i++) er[i] = 1;
	int x, y; cin >> x >> y;
	if (y >= m) {
		cout << 0;
		//continue;
		return 0;
	}
	if (x == 0) {
		cout << m - y;
		//continue;
		return 0;
	}
	vi es(2 * n, INF);
	int cnt = 0;
	for (int i = 0; i < x; i++) cnt += er[i];
	for (int i = 0; i < n; i++) {
		es[i] = cnt;
		cnt -= er[i];
		cnt += er[i + x];
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		ans = min(ans, es[i]);
	}
	if (ans <= y) cout << m - y;
	else cout << m - ans;
}
