#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int> > v(N * M + 1);

    for (int i = 1; i <= N * M; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            if (i % j) continue;
            int k = i / j;
            v[i].push_back(k - j);
        }
    }
    
    function<int(int, int, int)> f = [&](int n, int old, int k) {
        if (n == 1) return 0;

        int ret = 0;
        for (auto e: v[n - 1]) {
            if (abs(e - old) > k) continue;
            ret = max(ret, f(n - 1, e, k)) + 1;
        }
        return ret;
    };


    cout << f(N * M, abs(N - M), K);
}