#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
vector<int> one;


int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(1){
        int cnt_all = 0;
        int cnt_one = 0;
        int cnt_two = 0;
        for(int i=0; i<n; i++){
            int tmp = (int)adj[i].size();
            if(tmp > 0) cnt_all++;

            if(tmp == 2) cnt_two++;
            else if(tmp == 1){
                one.push_back(i);
                cnt_one++;
            }
        }
        if(cnt_one == 2 && cnt_all == cnt_one + cnt_two) break;

        for(int i=0; i<(int)one.size(); i++){
            int node = one[i];
            int next = adj[node][0];
            vector<int>().swap(adj[node]);
            for(int j=0; j<(int)adj[next].size(); j++){
                if(adj[next][j] == node){
                    adj[next].erase(adj[next].begin()+j);
                    break;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if((int)adj[i].size() > 0){
            cout << i << " ";
        }
    }
}
