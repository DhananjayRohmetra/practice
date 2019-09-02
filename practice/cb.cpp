
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, dist;
};
int main()
{
    freopen("input.txt", "r", stdin);
    int n, m, i, j, dis = -1;
    cin >> n >> m;
    char grid[n + 1][m + 1];
    int visited[n + 1][m + 1];
    memset(visited, 0, sizeof(visited));
    node source;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '0')
            {
                visited[i][j] = 1;
            }

            if (grid[i][j] == 's')
            {

                source.x = i;
                source.y = j;
                source.dist = 0;
            }
        }
    }
    queue<node> q;
    q.push(source);
    visited[source.x][source.y] = 1;
    while (!q.empty())
    {
        node t = q.front();
        q.pop();
        if (grid[t.x][t.y] == 'd')
        {
            dis = t.dist;
            break;
        }
        if (t.x - 1 >= 0 && visited[t.x - 1][t.y] == 0)
        {
            node p;
            p.x = t.x - 1;
            p.y = t.y;
            p.dist = t.dist + 1;
            q.push(p);
            visited[t.x - 1][t.y] = 1;
        }

        if (t.x + 1 < n && visited[t.x + 1][t.y] == 0)
        {
            node p;
            p.x = t.x + 1;
            p.y = t.y;
            p.dist = t.dist + 1;
            q.push(p);
            visited[t.x + 1][t.y] = 1;
        }

        if (t.y - 1 >= 0 && visited[t.x][t.y - 1] == 0)
        {
            node p;
            p.x = t.x;
            p.y = t.y - 1;
            p.dist = t.dist + 1;
            q.push(p);
            visited[t.x][t.y - 1] = 1;
        }

        if (t.y + 1 < m && visited[t.x][t.y + 1] == 0)
        {
            node p;
            p.x = t.x;
            p.y = t.y + 1;
            p.dist = t.dist + 1;
            q.push(p);
            visited[t.x][t.y + 1] = 1;
        }
    }
    cout << dis << " ";
}