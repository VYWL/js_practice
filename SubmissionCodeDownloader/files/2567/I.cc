#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > v(N, vector<int> (N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    function<int(int, int, int)> f = [&](int r, int c, int sz) {
        if (sz == 1) {
            return v[r][c];
        }

        vector<int> vv;
        int half = sz >> 1;
        vv.push_back(f(r, c, half));
        vv.push_back(f(r + half, c, half));
        vv.push_back(f(r, c + half, half));
        vv.push_back(f(r + half, c + half, half));

        sort(vv.begin(), vv.end());
        return vv[1];
    };

    cout << f(0, 0, N) << '\n';
}