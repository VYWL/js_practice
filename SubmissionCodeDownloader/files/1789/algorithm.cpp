#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long double x, y, h, d;
        cin >> x >> y >> h >> d;
        d -= x;
        h -= y;
        long double hypo = sqrt(x * x + y * y);
        long double co = x / hypo, si = y / hypo, ta = si / co;

        long double ans = sqrt((5.0 * d * d) / (co * co * (d * ta - h)));
        if (d * ta <= h || ans > 1000000.0)
            cout << "-1\n";
        else
            cout << ceil(ans) << '\n';
    }

    return 0;
}
