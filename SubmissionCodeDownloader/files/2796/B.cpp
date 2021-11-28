#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int n, m, tmp;
    vector<int> errln;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        errln.push_back(tmp);
    }
    int x,y;
    cin >> x >> y;

    vector<pair<int,int>> _errln;
    _errln.push_back(make_pair(1,errln[1]-1));
    for (int i = 1; i < m-1; i++)
    {
        _errln.push_back(make_pair(errln[i-1]+1, errln[i+1]-1));
    }
    _errln.push_back(make_pair(errln[errln.size()-1]+1, n));

    while (y <= m)
    {
        for (int i = 0; i < m-y+1; i++)
        {
            if(_errln[i+y-1].second - _errln[i].first >= x){
                cout << m - y << endl;
                return 0;
            }
        }
        y++;
    }
    cout << 0 << endl;
    return 0;
    
}