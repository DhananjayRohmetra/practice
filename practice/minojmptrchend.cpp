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
        int n, i, j;
        cin >> n;
        int arr[n + 1], dp[n + 1];
        for (i = 0; i < n; i++)
        {
            dp[i] = 10000001;
        }
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        dp[0] = 0;
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < i; j++)
            {
                if (j + arr[j] >= i)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        if(dp[n-1]!=10000001)
        {
        cout << dp[n - 1] << "\n";
        }
        else
        {
          cout <<"-1\n";  
        }
    }
}