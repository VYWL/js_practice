#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> error(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        error[num] = true;
    }
    int X, Y;
    cin >> X >> Y;


    int cnt = 0;
    int prev = -1;
    int tmp = 0;

    for (int i = 1; i <= N; ++i) {
        if (!error[i]) {
            if (cnt == 0) {
                ++cnt;
            } else if (prev + 1 == i) {
                ++cnt;
            } else {
                cnt = 0;
            }

            tmp = max(tmp, cnt);
            prev = i;
        }
    }

    int mustDel = max(0, X - tmp);

    int del = max(Y, mustDel);

    cout << M - del << '\n';


    // vector<int> v(M);

    // for (auto& e: v) cin >> e;

    // int X, Y;
    // cin >> X >> Y;

    // int cnt = 0;
    // int prev = -1;
    // int del = 0;
    // for (auto e: v) {
    //     if (cnt == 0) {
    //         ++cnt;
    //     } else if (prev + 1 == e) {
    //         ++cnt;
    //     }

    //     if (cnt > X) {
    //         ++del;
    //         cnt = 0;
    //     }
    //     prev = e;
    // }

    // del = max(del, Y);

    // cout << M - del << '\n';
}