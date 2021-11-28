#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;
const int MAX = 100005, INF = 1000000001, MOD = 9901;

int a[1024][1024];

int f(int sx, int ex, int sy, int ey) {
	if (sx == ex) {
		return a[sx][sy];
	}

	vi b;
	int n = ex + sx + 1, n1 = ey + sy + 1;
	b.push_back(f(sx, n / 2 - 1, sy, n1 / 2 - 1));
	b.push_back(f(n / 2, ex, sy, n1 / 2 - 1));
	b.push_back(f(sx, n / 2 - 1, n1 / 2, ey));
	b.push_back(f(n / 2, ex, n1 / 2, ey));
	sort(b.begin(), b.end());

	return b[1];
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	cout << f(0, n - 1, 0, n - 1) << '\n';

	return 0;
}