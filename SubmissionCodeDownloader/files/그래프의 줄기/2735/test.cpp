// https://www.acmicpc.net/problem/
//
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph; // next, removed
vector<int> removed, graphEdge;

int dfs(int now, int prev)
{
    if (graphEdge[now] == 1) // 이 정점을 지워야 할 때.
    {
        // find(graph[now].begin(), graph[now].end(), prev);
        // find(graph[prev].begin(), graph[prev].end(), now);
        for (auto &it : graph[now])
            if (it.first == prev)
            {
                it.second = 1;
                break;
            }
        for (auto &it : graph[prev])
            if (it.first == now)
            {
                it.second = 1;
                break;
            }
        graphEdge[now]--;
        graphEdge[prev]--;
        removed.push_back(now);
        // 예외처리
        if (graphEdge[prev] == 0)
            removed.push_back(prev);
        return 1;
    }
    int ret = 0;
    for (auto &next : graph[now])
        if (prev != next.first and !next.second)
            ret += dfs(next.first, now);
    return ret;
}

int findStart()
{
    for (int i = 0; i < graph.size(); i++)
    {
        int tmp = 0;
        for (auto &it : graph[i])
            if (it.second == 0)
                tmp++;
        if (tmp >= 2)
            return i;
    }
}

int main(void)
{
    // 줄기 -> 갈 수 있는 정점이 하나거나(끝), 둘(양쪽)
    // 그렇다면, 지울 수 있는 정점이 두개일 때 줄기이다.
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

    // dfs는 갈 수 있는 정점이 두 개 이상인 점에서 시작해야함.
    int check = 0;
    while (check != 2)
    {
        removed.assign(0, 0);
        check = dfs(findStart(), -1);
    }

    vector<int> remain;
    for (int i = 0; i < graph.size(); i++)
        for (auto &it : graph[i])
            if (it.second == 0)
            {
                remain.push_back(i);
                break;
            }

    for (int i : removed)
        remain.push_back(i);

    sort(remain.begin(), remain.end());

    for (int i : remain)
        printf("%d ", i);
}

/*
    
*/