#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ans = 0;
    cin >> n;
    int arr[n + 1], brr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int findb[n + 2];
    memset(findb, 0, sizeof(findb));
    int idx;
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i];
        findb[brr[i]]++;
    }
    int sus;
    for (int i = 1; i <= n; i++)
    {
        if (findb[i] == 1)
        {
            sus = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (brr[i] == sus)
        {
            idx = i;
            break;
        }
    }
    int s = n;
    int flag = 0, nwidx;
    for (int i = idx; i <= n; i++)
    {
        if (brr[i] < i - idx + 1 && i != idx && brr[i] != 0)
        {
            nwidx = i;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        int i, y = 1;
        for (i = idx; i <= n; i++)
        {
            if (brr[i] == y)
                y++;
            else
                break;
        }
        if (i == n + 1)
        {
            cout << "by3";
            int u = 0;
            int res = y;
            for (i = 1; i <= idx - 1;)
            {
                if (i == 1)
                {
                    if (brr[i] == 0)
                    {
                        i++;
                    }
                    if (findb[y] == 0)
                    {
                        u = 1;
                        y++;
                        if (y == n + 1)
                            break;
                    }
                    else if (brr[i] == y && y != res)
                    {
                        u = 1;
                        y++;
                        i++;
                        if (y == n + 1)
                            break;
                    }
                    else
                        break;
                }
                else if (u == 1)
                {
                    if (brr[i] == 0)
                    {
                        i++;
                    }
                    if (findb[y] == 0 && y <= n)
                    {
                        y++;
                        if (y == n + 1)
                            break;
                    }
                    if (brr[i] == y)
                    {
                        i++;
                        y++;
                        if (y == n + 1)
                            break;
                    }
                    else if ((findb[y] != 0 && brr[i] != y) || y == n + 1)
                        break;
                }
            }
            if (y == n + 1)
                ans = idx - 1;
            else
                ans = idx + n;
        }
        else
        {
            ans = idx + n;
        }
    }
    else
    {
        ans = nwidx + n - (brr[nwidx] - 1);
    }
    cout << ans;
}