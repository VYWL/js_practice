#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<math.h>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long x, y, h, d;
		cin >> x >> y >> h >> d;
		long double c = sqrt(x * x + y * y);
		long long l = 1, r = 1000000, ans = -1;
		while (l <= r) {
			long long mid = (l + r) / 2;
			long double xv = mid * x / c, yv = mid * y / c;
			long double t = (d - x) / xv;
			if (t < 0)break;
			if (yv * t - (10) * t * t / 2 + y >= h) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << "\n";
	}
}