#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    
    function<int(int, int, int)> f = [&](int n, int old, int k) {
        if (n == 0) return 0;

        int ret = 0;
        for (int i = 1; i * i <= n - 1; ++i) {
            int j = n / i;
            if (i * j != n - 1) continue;
            if (abs(old - (j - i)) > k) continue;
            ret = max(ret, f(n - 1, j - i, k)) + 1;
        }

        return ret;
    };

    cout << f(N * M, abs(N - M), K);

}