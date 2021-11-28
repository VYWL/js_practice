#include <bits/stdc++.h>

using namespace std;


int main() {
  	cin.tie(NULL);
	  ios::sync_with_stdio(false);

    int ans = -1;
    int N, M, K, cur;
    int X, Y;
    vector<int> errors = {0};
    vector<int> terms = {0, 0};

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
      cin >> K;
      errors.push_back(K);
    }
    cin >> X >> Y;

    sort(errors.begin(), errors.end());
    for (int i = 1; i < M; i++) {
      terms.push_back(errors[i] - errors[i - 1]);
    }
    for (int i = 1; i < M + 1; i++) {
      terms[i] += terms[i - 1];
    }

    cur = Y - 1;
    while (ans < X) {
      cur++;
      for (int i = cur + 1; i < M + 1; i++) {
        ans = max(ans, terms[i] - terms[i - cur - 1] - 1);
        if (ans >= X) break;
      }
    }
    cout << M - cur;
}