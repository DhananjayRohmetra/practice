#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n + 1][n + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int dis[n + 1][n + 1];
        memset(dis, 999999, sizeof(dis));
        dis[0][0] = arr[0][0];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        pair<int, int> top;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            top = pq.top().second;

            pq.pop();
            int x;
            int y;
            for (int i = 0; i < 4; i++)
            {
                //cout<<top.first+dx[i]<< " "<<top.second+dy[i]<<"\n";
                x = top.first + dx[i];
                y = top.second + dy[i];
                if ((x >= 0 && x < n) && (y >= 0 && y < n))
                {
                    int weight = arr[x][y];
                    if (dis[x][y] > dis[top.first][top.second] + weight)
                    {
                        dis[x][y] = dis[top.first][top.second] + weight;
                        pq.push({dis[x][y], {x, y}});
                    }
                }
            }
        }
        cout << dis[n - 1][n - 1] << "\n";
    }
}
