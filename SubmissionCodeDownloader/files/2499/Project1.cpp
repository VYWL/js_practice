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

	string s; cin >> s;
	for (int i = 0; i < s.length() - 1; i++) {
		cout << s[i] << "__";
	}
	cout << s[s.length() - 1];
}
