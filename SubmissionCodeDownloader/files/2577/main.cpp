#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[2048][2048];
int two[11] = {1,2,4,8,16,32,64,128,256,512,1024};
vector<int> v;

void gogo(int x,int y,int z,int w){
    if(y-x == 1){
        vector<int> ok;
        ok.push_back(a[x][z]);
        ok.push_back(a[x][w]);
        ok.push_back(a[y][z]);
        ok.push_back(a[y][w]);
        sort(ok.begin(),ok.end());
        v.push_back(ok[1]);
        return;
    }
    else{
        int m1 = (x+y)/2;
        int m2 = (z+w)/2;
        //x+y/2
        gogo(x,m1,z,m2);
        gogo(x,m1,m2+1,w);
        gogo(m1+1,y,z,m2);
        gogo(m1+1,y,m2+1,w);
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    if(n == 1) cout << a[0][0];
    else if(n == 2){
        v.push_back(a[0][0]);
        v.push_back(a[0][1]);
        v.push_back(a[1][0]);
        v.push_back(a[1][1]);
        sort(v.begin(),v.end());
        cout << v[1];
    }
    else{
        gogo(0,two[n]-1,0,two[n]-1);
        sort(v.begin(),v.end());
        cout << v[1];
    }
}
