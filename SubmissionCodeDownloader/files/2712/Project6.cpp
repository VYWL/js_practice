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
	vvp adj(n); vi child(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	if (n == 2) {
		cout << adj[0][0].second << endl << adj[0][0].second;
		return 0;
	}
	int s;
	for (int i = 0; i < n; i++) if (adj[i].size() != 1) s = i;
	vi cost(n, -1), par(n); par[s] = -1;
	cost[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (pii nxt : adj[cur]) {
			if (cost[nxt.first] != -1) continue;
			q.push(nxt.first);
			cost[nxt.first] = cost[cur] + nxt.second;
			par[nxt.first] = cur;
			child[cur]++;
		}
	}
	vector<pii> vp(n, { 0, INF }), ans(n, { 0, INF });
	for (int i = 0; i < n; i++) {
		if (child[i] == 0) {
			vp[i] = { cost[i], cost[i] };
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == s) break;
		ans[par[cur]].first = max(ans[par[cur]].first, vp[par[cur]].first + vp[cur].first);
		ans[par[cur]].second = min(ans[par[cur]].second, vp[par[cur]].second + vp[cur].second);
		vp[par[cur]].first = max(vp[par[cur]].first, vp[cur].first);
		vp[par[cur]].second = min(vp[par[cur]].second, vp[cur].second);
		child[par[cur]]--;
		if (child[par[cur]] == 0) q.push(par[cur]);
	}
	int ans1 = 0, ans2 = INF;
	for (int i = 0; i < n; i++) {
		ans1 = max(ans1, ans[i].first - 2*cost[i]);
		//cout << i << ' ' << vp[i].first << ' ' << vp[i].second << endl; 
		ans2 = min(ans2, ans[i].second - 2*cost[i]);
	}
	cout << ans1 << endl << ans2;
}
