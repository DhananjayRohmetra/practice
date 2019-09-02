#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2e+15 + 7;
ll n, a, b;
char arr[200009];
ll dp[200009][3];

int main()
{
    freopen("input.txt", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        for (ll i = 0; i < n; i++)
            cin >> arr[i];
        dp[0][0] = b;
        dp[0][1] = MAXN;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i - 1] == '0')
            {
                dp[i][0] = min(dp[i - 1][0] + a, dp[i - 1][1] + 2 * a) + b;
                dp[i][1] = min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a) + 2 * b;
            }
            else
            {
                dp[i][1] = dp[i - 1][1] + a + 2 * b;
                dp[i][0] = MAXN;
            }
        }
        cout << dp[n][0] << "\n";
    }
}