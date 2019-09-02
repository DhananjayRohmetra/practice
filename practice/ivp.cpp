#include <bits/stdc++.h>
using namespace std;
int m, n;
int dp[203][203][3];
char arr[203][203];
int dfs(int i, int j, int dir)
{
    if (i < 0 || i >= n || j < 0 || j >= m || arr[i][j] == 'X')
        return 0;

    if (dp[i][j][dir] != -1)
        return dp[i][j][dir];
    if (dir == 1)
    {
        if (arr[i][j] == '1')
        {
            dp[i][j][dir] = 1 + max(dfs(i + 1, j, 0), dfs(i, j + 1, 1));
        }
        else
        {
            dp[i][j][dir] = max(dfs(i + 1, j, 0), dfs(i, j + 1, 1));
        }
    }
    if (dir == 0)
    {
        if (arr[i][j] == '1')
        {
            dp[i][j][dir] = 1 + max(dfs(i + 1, j, 1), dfs(i, j - 1, 0));
        }
        else
        {
            dp[i][j][dir] = max(dfs(i + 1, j, 1), dfs(i, j - 1, 0));
        }
    }
    return dp[i][j][dir];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));
        cout << dfs(0, 0, 1);
    }
}
