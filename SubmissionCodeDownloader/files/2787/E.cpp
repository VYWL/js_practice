#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int max = abs(n-m) + k;
    int now = n*m;
    int cnt = 0;
    bool can = true;

    while (can) // n*m
    {
        if(cnt == n*m-1) break;

        vector<int> v; // n
        for (int i = 1; i*i <= now-1; i++)
        {
            if ((now-1) % i == 0)
                v.push_back(i);
        }
        for (int i = v.size(); i > 0; i--) //n
        {
            if(abs(v[i-1] - (now-1)/v[i-1]) <= max){
                cnt++;
                now--;
                can = true;
                break;
            }
            can = false;
        }
    }

    cout << cnt << endl;
    
}