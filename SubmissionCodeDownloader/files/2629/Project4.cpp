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

signed main() {
	IOS;

	int n; cin >> n;
	vector<pii> se(n); //caff, eff
	for (int i = 0; i < n; i++) cin >> se[i].second;
	for (int i = 0; i < n; i++) cin >> se[i].first;
	sort(se.begin(), se.end(), greater<pii>());
	vvi dp(n + 1, vi(n + 1)); // dp[a][b] a앞에서 b개를 쳐먹었을때 제일 이득
	int t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int x = 0; x < j; x++) {
				dp[j][i] = max(dp[j][i], dp[x][i - 1] + se[x].second - se[x].first * (i - 1));
			}
		}
	}
	cout << *max_element(dp[n].begin(), dp[n].end());
}
