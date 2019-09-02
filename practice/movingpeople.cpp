#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m, q;
    cin >> n >> m >> q;
    char arr[n + 1][m + 1];
    int aux[n + 1][m + 1], pref[n + 1][m + 1], x, y, z, top = 0, down = n - 1, left = 0, right = m - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] - '0' == 0)
            {
                aux[i][j] = 0;
            }
            if (arr[i][j] - '0' == 1)
            {
                aux[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        pref[i][0] = aux[i][0];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            pref[i][j] = pref[i][j - 1] + aux[i][j];
        }
    }

    int maxLeft = 0, minRight = m - 1, maxUp = 0, minDown = n - 1, Left = 0, Right = m - 1, Up = 0, Down = n - 1;
    while (q--)
    {
        cin >> z;
        if (z == 1)
        {
            cin >> x >> y;
            Left = Left + x;
            Right = Right + x;
            Up = Up + y;
            Down = Down + y;
            maxLeft = max(Left, maxLeft);
            minRight = min(Right, minRight);
            maxUp = max(Up, maxUp);
            minDown = min(Down, minDown);
        }
        if (z == 2)
        {

            int ans = 0;
            //cout<<maxLeft<<" "<<minRight<<" "<<maxUp<<" "<<minDown<<"\n";
            if (maxLeft > minRight || maxUp > minDown)
            {
                cout << "0\n";
            }
            else
            {
                for (int i = maxUp; i <= minDown; i++)
                {
                    ans = ans + pref[i][minRight];
                    if (maxLeft != 0)
                    {
                        ans = ans - pref[i][maxLeft - 1];
                    }
                }
                cout << ans << "\n";
            }

            // maxLeft = -1, minRight = 10000, maxUp = -1, minDown = 10000;
        }
    }
}