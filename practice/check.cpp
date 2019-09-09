#include <bits/stdc++.h>
using namespace std;
int n, m, ans[509][509], countt = 0;
char str[509][509];
void dfs(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
    {
        return ;
    }
    else
    {
        if (ans[i][j] == 0 && str[i][j]=='.')
        {
        
            ans[i][j] = 1;
            countt++;
        

        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
        }
    }
}
int main()
{
	freopen("input.txt", "r", stdin);
    int i, j, anss = -1;
    cin >> n >> m;
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> str[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (ans[i][j] == 0 && str[i][j]=='.')
            {
                countt = 0;
                dfs(i, j);
                anss = max(countt, anss);
            }
        }
    }
    cout << anss;
    return 0;
}

