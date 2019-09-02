#include <bits/stdc++.h>
using namespace std;
int n, dp[3][107][107][107], arr[107], brr[107];
int recur(int p, int p1, int p2, int idx)
{
    //cout << p << " " << p1 << " " << p2 << " " << idx << "\n";
    if (idx >= n)
    {
        return 0;
    }
    if (p == 1)
    {
        if (dp[p][p1][p2][idx] != -1)
            return dp[p][p1][p2][idx];

        if (p1 == 0)
        {
            dp[p][p1][p2][idx] = brr[idx] + recur(2, p1, p2 - 1, idx + 1);
            return dp[p][p1][p2][idx];
        }
        if (p1 != 0)
        {
            dp[p][p1][p2][idx] = arr[idx] + max(recur(1, p1 - 1, p2, idx + 1), recur(2, p1 - 1, p2, idx + 1));
            return dp[p][p1][p2][idx];
        }
    }
    if (p == 2)
    {
        if (dp[p][p1][p2][idx] != -1)
            return dp[p][p1][p2][idx];
        if (p2 == 0)
        {
            dp[p][p1][p2][idx] = arr[idx] + recur(2, p1 - 1, p2, idx + 1);
            return dp[p][p1][p2][idx];
        }

        if (p2 != 0)
        {
            dp[p][p1][p2][idx] = brr[idx] + max(recur(1, p1, p2 - 1, idx + 1), recur(2, p1, p2 - 1, idx + 1));
            return dp[p][p1][p2][idx];
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int i, p1, p2;
        cin >> n >> p1 >> p2;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> brr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << max(recur(1, p1, p2, 0), recur(2, p1, p2, 0)) << "\n";
    }
}