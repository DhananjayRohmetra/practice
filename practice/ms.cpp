#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n + 1];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int dp[k + 1][n + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[1][i] = arr[i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    for (int l = 1; l <= k - 1; l++)
                    {
                        if (dp[l][j] != -1)
                        {
                            dp[l + 1][i] = max(dp[l + 1][i], arr[i] + dp[l][j]);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[k][i]);
        }
        cout << ans << "\n";
    }
}