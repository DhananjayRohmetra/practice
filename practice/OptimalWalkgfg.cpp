#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        ll dp[100009];
        ll n, a, b;
        cin >> n >> a >> b;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                dp[i] = min(dp[i / 2] + b, dp[i - 1] + a);
            }
            else
            {
                dp[i] = min({dp[i / 2] + a + b, dp[i - 1] + a, dp[(i + 1) / 2] + a + b});
            }
        }
        cout << dp[n] << "\n";
    }
}