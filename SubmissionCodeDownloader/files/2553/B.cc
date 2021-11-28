#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;


    vector<int> v(M);

    for (auto& e: v) cin >> e;

    int X, Y;
    cin >> X >> Y;

    int cnt = 0;
    int prev = -1;
    int del = 0;
    for (auto e: v) {
        if (cnt == 0) {
            ++cnt;
        } else if (prev + 1 == e) {
            ++cnt;
        }

        if (cnt > X) {
            ++del;
            cnt = 0;
        }
        prev = e;
    }

    del = max(del, Y);

    cout << M - del << '\n';
}