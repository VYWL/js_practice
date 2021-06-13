#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int t, x, y, h, d;
    cin >> t;
    vector<vector<int>> v(t);
    for (int i = 0; i < t; i++) {
       cin >> x >> y >> h >> d;
       v[i].push_back(x);
       v[i].push_back(y);
       v[i].push_back(h);
       v[i].push_back(d);
    }
    double vx,vy,ys;
    int time,vel;
    for (int i = 0; i < t; i++)
    {
        int x = v[i][0];
        int y = v[i][1];
        int h = v[i][2];
        int d = v[i][3];
        for (vel = 1; vel < pow(10,6); vel++)
        {
            vx = vel*x/sqrt(pow(x,2) + pow(y,2));
            vy = vel*y/sqrt(pow(x,2) + pow(y,2));
            t = d-x/vx;
            ys = vy*t+y-50*pow(t,2);
            if (ys >= h){
                v[i].push_back(vel);
                break;
            }
        }
        if(vel == pow(10,6)) 
        {
            vel = -1;
          v[i].push_back(vel);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i][4] << endl;
    }
    
    
}