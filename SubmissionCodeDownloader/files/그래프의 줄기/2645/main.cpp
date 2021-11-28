#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
vector<int> one;
int degree[100001];
vector<int> all;

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
        all.push_back(i);
    }

    while(1){
        int cnt_all = 0;
        int cnt_one = 0;
        int cnt_two = 0;
        for(int i=0; i<(int)all.size(); i++){
            int tmp = all[i];
            if(degree[tmp] == 2) cnt_two++;
            else if(degree[tmp] == 1){
                one.push_back(tmp);
                cnt_one++;
            }
        }
        if(cnt_one == 2 && (int)all.size() == cnt_one + cnt_two) break;

        for(int i=0; i<(int)one.size(); i++){
            int node = one[i];
            for(int j=0; j<(int)adj[node].size(); j++){
                int next = adj[node][j];
                degree[next]--;
            }
            degree[node]--;
            vector<int>().swap(adj[node]);
            all.erase(lower_bound(all.begin(),all.end(),node));
        }
        vector<int>().swap(one);
    }
    for(int i=0; i<(int)all.size(); i++){
        cout << all[i] << " ";
    }
}
