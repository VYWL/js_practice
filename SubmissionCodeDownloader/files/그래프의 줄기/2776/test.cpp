// https://www.acmicpc.net/problem/
//
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<pair<int, int>>> graph; // next, removed
    vector<int> graphEdge;

    int n;
    scanf("%d", &n);
    graph.assign(n, vector<pair<int, int>>());
    graphEdge.assign(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back({b, 0});
        graph[b].push_back({a, 0});
    }

    for (int i = 0; i < n; i++)
        graphEdge[i] = graph[i].size();

    while (true)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (graphEdge[i] == 1)
                cnt++;

        if (cnt == 2)
            break;

        for (int i = 0; i < n; i++)
        {
            if (graphEdge[i] == 1)
            {
                int next = -1;
                for (int j = 0; j < graph[i].size(); j++)
                    if (graph[i][j].second == 0)
                    {
                        graph[i][j].second = 1;
                        next = graph[i][j].first;
                    }
                for (int j = 0; j < graph[next].size(); j++)
                    if (graph[next][j].first == i)
                    {
                        graph[next][j].second = 1;
                    }
                graphEdge[next]--;
                graphEdge[i]--;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (graphEdge[i])
            ans.push_back(i);

    sort(ans.begin(), ans.end());

    for (int i : ans)
        printf("%d ", i);
}

/*
    
*/