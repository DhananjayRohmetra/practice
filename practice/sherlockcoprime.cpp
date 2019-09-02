#include <bits/stdc++.h>
using namespace std;
int n, arr[60], p, dp[60][32778];
int prime[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int recur(int curr, int mask)
{
    if (curr == n || mask == p)
        return 0;
    if (dp[curr][mask] != -1)
        return dp[curr][mask];
    int q = recur(curr + 1, mask);
    if (arr[curr] == 1)
    {
        dp[curr][mask] = q + 1;
        return dp[curr][mask];
    }
    int newmask = mask;
    for (int i = 0; i < 15; i++)
    {
        if (arr[curr] % prime[i] == 0)
        {
            if (mask & (1 << i))
            {
                return dp[curr][mask] = q;
            }
            else
            {
                newmask = newmask | (1 << i);
            }
        }
    }

    return dp[curr][mask] = max(1 + recur(curr + 1, newmask), q);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        p = (1 << 15) - 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << recur(0, 0) << "\n";
    }
}