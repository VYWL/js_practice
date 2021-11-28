#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> error(N + 2, false);
    error[0] = true;
    error[N + 1] = true;
    vector<int> perror(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        error[num] = true;
    }
    for (int i = 1; i <= N; ++i) {
        perror[i] += perror[i - 1];
        perror[i] += error[i];
    }

    int X, Y;
    cin >> X >> Y;

    // int i = 1;
    // int j = N;

    int del = 1e9;
    // while (i <= j) {
    //     if (!(error[i - 1] && !error[i])) {
    //         ++i;
    //         continue;
    //     }

    //     if (!(error[j + 1] && !error[j])) {
    //         --j;
    //         continue;
    //     }

    //     if (j - i + 1 >= X) {
    //         del = min(del, perror[j] - perror[i - 1]);
    //     }
    //     ++i;
    // }

    if (del == 1e9) {
        for (int i = 1; i <= N; ++i) {
            int j = i + X - 1;
            if (j > N) continue;
            del = min(del, perror[j] - perror[i - 1]);
        }
    }
    cout << M - max(Y, del) << '\n';
}
