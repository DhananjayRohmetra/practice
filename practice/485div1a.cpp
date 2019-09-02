#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<vector<int>> adj;
vector<vector<int>> q;
int zm[700002];
int main()
{
    // freopen("input.txt", "r", stdin);
    int u, v, n, m, k, ss, s;
    cin >> n >> m >> k >> ss;
    int krr[n + 1];
    adj.resize(n + 1);
    q.resize(k + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> krr[i];
        q[krr[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dist[k + 1][n + 1];
    for (int i = 1; i <= k; i++)
    {
        for (int x = 1; x <= n; x++)
        {
            dist[i][x] = INF;
        }
        int idx = 0;
        int sz = q[i].size();

        for (auto it = q[i].begin(); it != q[i].end(); ++it)
        {
            dist[i][*it] = 0;
            zm[idx] = *it;
            idx++;
        }
        int topQ = q[i].size();
        for (int cc = 0; cc < topQ; cc++)
        {
            s = zm[cc];
            for (int cnt = 0; cnt < adj[s].size(); cnt++)
            {
                if (dist[i][adj[s][cnt]] >= dist[i][s] + 1)
                {
                    dist[i][adj[s][cnt]] = dist[i][s] + 1;
                    zm[topQ++] = adj[s][cnt];
                }
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        int res[k + 2];
        memset(res, 0, sizeof(res));
        for (int j = 1; j <= k; j++)
        {
            res[j] = dist[j][x];
        }
        sort(res + 1, res + k + 1);
        int s = 0;
        for (int i = 1; i <= ss; i++)
        {

            s += res[i];
        }
        cout << s << " ";
    }
}