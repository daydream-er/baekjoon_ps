#include<iostream>
#include<vector>
using namespace std;

// 모르면 못 푸는 문제...
// DFS는 깊이우선탐색이다. 즉, 가장 바깥 노드를 탐색하기 쉽다.

int vertex[100001];
pair<int, int>  max_vertex;
vector<pair<int, int> > edge[100001];
bool    visited[100001];

void    dfs(int s_vertex, int cur_weight)
{
    visited[s_vertex] = true;
    for (int i = 0; i < edge[s_vertex].size(); i++)
    {
        int e_vertex, weight;

        e_vertex = edge[s_vertex][i].first;
        weight = edge[s_vertex][i].second;
        if (visited[e_vertex])
            continue;
        if (max_vertex.second < cur_weight + weight)
        {
            max_vertex.second = cur_weight + weight;
            max_vertex.first = e_vertex;
        }
        dfs(e_vertex, cur_weight + weight);
    }
}

int main(void)
{
    int V;

    cin >> V;
    for (int i = 0; i < V; i++)
    {
        int s_vertex, e_vertex, weight;

        cin >> s_vertex;
        while (true)
        {
            cin >> e_vertex;
            if (e_vertex == -1)
                break ;
            cin >> weight;
            edge[s_vertex].push_back(make_pair(e_vertex, weight));
        }
    }
    max_vertex.second = -1;
    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
            continue;
        dfs(i, 0);
    }
    max_vertex.second = -1;
    // cout << max_vertex.first << "<<< \n";
    for (int i = 1; i <= V; i++)
        visited[i] = false;
    dfs(max_vertex.first, 0);
    // cout << max_vertex.first << "<<< \n";
    cout << max_vertex.second << "\n";
    return (0);    
}