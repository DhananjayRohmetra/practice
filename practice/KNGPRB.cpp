#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y, src, dst;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj;
        adj.resize(n + 1);
        int dis[n + 1];
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 99999999;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            adj[x].push_back({y, 0});
            adj[y].push_back({x, 1});
        }
        cin >> src >> dst;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pair<int, int> top;
        dis[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            top = pq.top();
            int s = top.second;

            pq.pop();
            for (auto it = adj[s].begin(); it != adj[s].end(); ++it)
            {
                int weight = (*it).second;
                int v = (*it).first;
                //cout<<v<<"\n";
                if (dis[v] > dis[s] + weight)
                {
                    dis[v] = dis[s] + weight;
                    pq.push({dis[v], v});
                }
            }
        }
        if (dis[dst] == 99999999)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dis[dst] << "\n";
        }
    }
}