#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> findDivisor(int a){
    vector<int> v;
    for (int i = 1; i*i <= a; i++)
    {
        if (a % i == 0)
            v.push_back(i);
    }
    return v;
}

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

        vector<int> v = findDivisor(now-1); // n
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