#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i = 0; i + 1< s.size(); ++i) {
        cout << s[i] << "__";
    }
    cout << s.back();
}