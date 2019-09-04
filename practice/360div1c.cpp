#include <bits/stdc++.h>
using namespace std;
bool dp[505][505][505];
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int u = 0; u <= j; u++)
            {
                dp[i][j][u] = dp[i - 1][j][u];
                if (j >= arr[i])
                {
                    dp[i][j][u] |= dp[i - 1][j - arr[i]][u];
                    if (u >= arr[i])
                    {
                        dp[i][j][u] |= dp[i - 1][j - arr[i]][u - arr[i]];
                    }
                }
            }
        }
    }
    vector<int> res;
    for (int i = 0; i <= k; i++)
    {
        if (dp[n][k][i])
        {
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
