#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> vec;
bool arr[100001][100001] = {false};
int in_degree[100001] = {0};
int n;
bool flag = true;
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int v, w;
    for(int i = 0; i <= n; i++) {
        vector<int> v1;
        vec.push_back(v1);
    }
    for(int i = 1; i <= n; i++) {
        cin >> v >> w;
        arr[v][w] = true;
        arr[w][v] = true;
    }
    while(true) {
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(in_degree[i] == 1) {
                in_degree[i]--;
                cnt++;
                for(int j = 1; j <= n; j++) {
                    if(arr[i][j]) {
                        arr[i][j] = false;
                        in_degree[j]--;
                    }
                }
            }
        }
        if(cnt <= 2) break;
    }
    for(int i = 1; i <= n; i++) {
        if(in_degree[i] != 0) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
