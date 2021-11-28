#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<vector<int>> vec){
    int n = vec[0].size();
    if (n != 2)
    {
        vector<vector<int>> tmp1,tmp2,tmp3,tmp4;
        int tmp;

        for (int i = 0; i < n/2; i++)
        {
            vector<int> vtmp;
            tmp1.push_back(vtmp);
            for (int j = 0; j < n/2; j++)
            {
                tmp1[i].push_back(vec[i][j]);
            }
        }
        for (int i = 0; i < n/2; i++)
        {
            vector<int> vtmp;
            tmp2.push_back(vtmp);
            for (int j = 0; j < n/2; j++)
            {
                tmp2[i].push_back(vec[n/2+i][j]);
            }
        }
        for (int i = 0; i < n/2; i++)
        {
            vector<int> vtmp;
            tmp3.push_back(vtmp);
            for (int j = 0; j < n/2; j++)
            {
                tmp3[i].push_back(vec[i][n/2+j]);
            }
        }
        for (int i = 0; i < n/2; i++)
        {
            vector<int> vtmp;
            tmp4.push_back(vtmp);
            for (int j = 0; j < n/2; j++)
            {
                tmp4[i].push_back(vec[n/2+i][n/2+j]);
            }
        }
        vector<int> arr;
        arr.push_back(find(tmp1));
        arr.push_back(find(tmp2));
        arr.push_back(find(tmp3));
        arr.push_back(find(tmp4));
        sort(arr.begin(), arr.end());

        return arr[1];

    } else {
        vector<int> arr;
        arr.push_back(vec[0][0]);
        arr.push_back(vec[0][1]);
        arr.push_back(vec[1][0]);
        arr.push_back(vec[1][1]);
        sort(arr.begin(), arr.end());

        return arr[1];
    }
    
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> v;
    int tmp;

    for (int i = 0; i < n; i++)
    {
        vector<int> vtmp;
        v.push_back(vtmp);
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    cout << find(v) << endl;
    
}