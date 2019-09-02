#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    cin >> str;
    int n = str.length();
    bool dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    int start, maxlen = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = true;
            maxlen = 2;
            start = i;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = k + i - 1;
            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = true;
                if (k > maxlen)
                {
                    maxlen = k;
                    start = i;
                }
            }
        }
    }
    for (int j = start; j < start + maxlen; j++)
    {
        cout << str[j];
    }
}