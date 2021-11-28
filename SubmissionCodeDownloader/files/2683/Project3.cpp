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

	int n, m, k; cin >> n >> m >> k;
	k += abs(m - n);
	const int maxi = n * m + 10;
	vi check(maxi, INF);
	for (int i = 1; i <= max(n, m); i++) {
		for (int j = i; j <= (i + k) && i*j < maxi; j++) {
			check[i * j] = min(check[i * j], j - i);
		}
	}
	int ans = n * m;
	for (; ans > 1; ans-- ) {
		if (check[ans] > k) {
			cout << n * m - (ans + 1);
			return 0;
		}
	}
	cout << n * m - 1;
}
