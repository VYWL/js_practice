#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
vector<int> one;
int degree[100001];

int main()
{

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        degree[i] = (int)adj[i].size();
    }

    while(1){
        int cnt_all = 0;
        int cnt_one = 0;
        int cnt_two = 0;
        for(int i=0; i<n; i++){
            if(degree[i] > 0) cnt_all++;

            if(degree[i] == 2) cnt_two++;
            else if(degree[i] == 1){
                one.push_back(i);
                cnt_one++;
            }
        }
        if(cnt_one == 2 && cnt_all == cnt_one + cnt_two) break;

        for(int i=0; i<(int)one.size(); i++){
            int node = one[i];
            for(int j=0; j<(int)adj[node].size(); j++){
                int next = adj[node][j];
                degree[next]--;
            }
            degree[node]--;
            vector<int>().swap(adj[node]);
        }
        vector<int>().swap(one);
    }
    for(int i=0; i<n; i++){
        if(degree[i] > 0){
            cout << i << " ";
        }
    }
}
