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

	int n, m; cin >> n >> m;
	int maxx = 0, before = -1;
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		if (i == 0) before = x;
		else {
			maxx = max(maxx, x - before);
			before = x;
		}
	}
	int X, Y; cin >> X >> Y;
	
	if (X > Y) cout << m - (X - Y) << '\n';
	else cout << m - Y << '\n';

	return 0;
}