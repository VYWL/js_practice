#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int>> findDivisor(int a){
    vector<pair<int,int>> v;
    for (int i = 1; i*i < a; i++)
    {
        if (a % i == 0)
            v.push_back(make_pair(i,a/i));
    }
    return v;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int max = abs(n-m) + k;
    int now = n*m;
    int cnt = 0;
    bool can;

    while (true)
    {
        if(cnt == n*m-1) break;

        vector<pair<int,int>> v = findDivisor(now-1);
        for (int i = 0; i < v.size(); i++)
        {
            if(abs(v[i].first - v[i].second) <= max){
                cnt++;
                now--;
                can = true;
                break;
            }
            can = false;
        }
        if(!can)
            break;
    }

    cout << cnt << endl;
    
}