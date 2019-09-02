#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001], dp[100001];
int go(int n)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    for (int i = 0; i < n; i++)
    {
        dp[n] = max(dp[n], arr[i] + go(n - i - 1));
    }
    return dp[n];
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(6);
}
